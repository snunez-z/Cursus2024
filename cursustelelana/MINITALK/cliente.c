// Recibe el PID del server, lo transforma con atoi en text y envia la señal SIGUSR1

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void client(const char *pid_str) 
{
    pid_t pid = atoi(pid_str);
    
    if (pid <= 0)
    {
        printf("PID inválido.\n");
        return (NULL);
    }

    if(kill(pid, SIGUSR1) == -1)
        return (NULL);  
    printf("Señal SIGUSR1 enviada al proceso con PID %d\n", pid);
}

int main(int argc, char *argv[])
 {
   if (argc <= 2) 
    {
        printf("usage %s <file> ...\n", argv[0]);
		return (-1);
    }
    client(argv[1]);
    return 0;
}