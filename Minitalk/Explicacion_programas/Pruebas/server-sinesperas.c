/* En este caso el server que esta dormido cuando recibe una señal, la funcion handler envia una señal 
al cliente para avisarle de que ha recibido la señal y que ya puede enviar otra, evitando la saturacion.
Para eso en el main tenemos que incluir el campo sa_flags, que lo que hace es indicarle al SO que tiene 
que rellenar los campos de la estructura SIGINFO_T. LO necesitamos para saber el remitente (campo si_pid del cliente).
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int count = 0;

void handle_sigusr1(int sig, siginfo_t *siginfo, void *context)
{
    (void)context; 
    if (kill(siginfo->si_pid, SIGUSR1) < 0) // si el envio de la señal SIGUSR1 al pid del cliente 
        printf("Error replying to PID %d\n", siginfo->si_pid);
    else
        printf("%d from %d\n", count, siginfo->si_pid);
    count++; 
}

int main() 
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa)); // inicializar ta cero todos los campos de sigaction saen una sola orden asi evitamos 
                                // que haya otros valores en esos espacios y evitamos inicializar uno a uno cada uno de los campos 
    sa.sa_flags = SA_SIGINFO; // Aqui definimos como queremos que nos llegue la señal, con info o son info 
    sa.sa_sigaction = handle_sigusr1; // Donde , a que funcion tienes que llamar cuando llegue la señal 
    if (sigaction(SIGUSR1, &sa, NULL) == -1) // Le estas diciendo la sistema operativo que te llame a la funcion hadler cuando llegue el sigusr1. 
                                             // funcion de aplicacion de las variables . Cuando llegue la señal, la tratas como he especificado en &sa 
        return (-1);
    printf("Server PID: %d\n", getpid());
    
    while (1) 
       pause();
      
    return 0;
}

