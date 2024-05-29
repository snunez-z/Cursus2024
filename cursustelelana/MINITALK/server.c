// mostrar el PID (PRINTF) decir cuando le llegue una señal y a dormir
// Cada vez que le llegue la señal SIGUSR1 tiene que sacar por pantalla Hola
/* SIGUSR1 y SIGUSR2 son señales definidas por el usuario para cualquier propósito.
    No tienen un significado predefinido por el sistema operativo.
    Se usan para la comunicación entre procesos o dentro del mismo proceso.
    Se identifican normalmente con los números 10 y 12.
    Se pueden enviar usando el comando kill y se manejan programáticamente mediante funciones específicas.*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void handle_sigusr1(int sig, void*siginfo, void *context)
{
    (void)context; 
    (void)siginfo;
    if (sig == SIGUSR1)
        printf("Hola");
   
}

int main() 
{
    struct sigaction_sa sa;
    memset(&sa, 0, sizeof(sa)); 
    sa.sa_sigaction = handle_sigusr1;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) 
        return (NULL);
    printf("Server PID: %d\n", getpid());
    while (1) 
        pause(); 
    return 0;
}

