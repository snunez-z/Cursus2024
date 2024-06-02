// Recibe el PID del server, lo transforma con atoi en text y envia la señal SIGUSR1
 // Para enviar una señal se usa el comando kill que recibe como parametros el pid de a quien tiene que enviar la señal y la señal a enviar, en este caso el SIGUSR1.
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
 {
	 int pid;
	 int count;

   if (argc < 2) 
    {
        printf("usage %s <file> ...\n", argv[0]);
		return (-1);
    }

    pid = atoi(argv[1]);
    if (pid == 0)
    {
        printf("PID inválido.\n");
        return 1;
    }

	count = 0;
	while (count < 1000)
	{
	    if(kill(pid, SIGUSR1) == -1)
	    {
        	printf("No he podido enviar la señal.\n");
        	return 1;  
    	}

    	printf("Señal SIGUSR1 enviada al proceso con PID %d\n", pid);
		usleep(50);
		count++;
	}
    return 0;
}
