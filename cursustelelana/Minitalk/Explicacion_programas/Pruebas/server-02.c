#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

// EJERCICIO
// Cambia la función handler para, en lugar de poner "Hola" cuando recibe una señal,
// ponga el número de señales que lleva procesadas
// Es decir, la primera vez que se llame al handler, ponga "1" (y salto de línea)
// La siguente vez, que ponga "2" (y salto de línea)
// Y así sucesivamente

int num_signal_processed;

num_signal_processed = 0;
void handle_sigusr1(int sig, siginfo_t* siginfo, void *context)
{
    (void)context; 
    (void)siginfo;
    if (sig == SIGUSR1)
        printf("Recibida la señal numero %d\n", num_signal_processed");
}

int main() 
{
    struct sigaction sign;
    
    memset(&sign, 0, sizeof(sign)); 
    sign.sa_sigaction = handle_sigusr1;

    if (sigaction(SIGUSR1, &sign, NULL) == -1) 
        return -1;
    printf("Server PID: %d\n", getpid());

    num_signal_processed = 0;
    while (num_signal_processed < 5)
    {
        pause();
        printf("Parece que he recibido una señal!! Seguiré durmiendo un rato más\n");
        num_signal_processed++;
    }
    return 0;
}

