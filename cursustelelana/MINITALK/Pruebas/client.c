// Recibe el PID del server, lo transforma con atoi en text y envia la señal SIGUSR1
 // Para enviar una señal se usa el comando kill que recibe como parametros el pid de a quien tiene que enviar la señal y la señal a enviar, en este caso el SIGUSR1.
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void client(const char *pid_str) 
{
    int pid = atoi(pid_str);
    if (pid == 0)
    {
        printf("PID inválido.\n");
        return;
    }

    if(kill(pid, SIGUSR1) == -1)
    {
        printf("No he podido enviar la señal.\n");
        return;  
    }
    printf("Señal SIGUSR1 enviada al proceso con PID %d\n", pid);
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
