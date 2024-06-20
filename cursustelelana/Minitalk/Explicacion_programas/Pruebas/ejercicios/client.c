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
