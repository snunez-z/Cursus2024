// Recibe el PID del server, lo transforma con atoi en text y envia la señal SIGUSR1
 // Para enviar una señal se usa el comando kill que recibe como parametros el pid de a quien tiene que enviar la señal y la señal a enviar, en este caso el SIGUSR1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

int count = 0;

void handle_sigusr1(int sig, siginfo_t *siginfo, void *context)
{
    (void)context; 
    count++;
    if (kill(siginfo->si_pid, SIGUSR1) < 0)
    {
        printf("No he podido enviar la señal.\n");
        return;  
    }

    printf("Enviada la señal %d\n", count);
}

void client(const char *pid_str) 
{
    int pid = atoi(pid_str);
    struct sigaction sa;
    
    if (pid == 0)
    {
        printf("PID inválido.\n");
        return;
    }

    memset(&sa, 0, sizeof(sa)); 
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_sigusr1;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) 
    {
        printf("No he podido poner el handler de escucha.\n");
        return;  
    }

    if(kill(pid, SIGUSR1) == -1) // Este va a inicializar una vez, el resto seria responsabilidad del handler
    {
        printf("No he podido enviar la señal.\n");
        return;  
    }
    printf("Señal SIGUSR1 enviada al proceso con PID %d\n", pid);
    while (count < 10000)

        usleep(1000);
}

int main(int argc, char *argv[])
 {
   if (argc < 2) 
    {
        printf("usage %s <file> ...\n", argv[0]);
		return (-1);
    }
    client(argv[1]);
    return 0;
}
