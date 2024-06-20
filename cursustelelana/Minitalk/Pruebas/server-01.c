/* Mi server que esta en pausa cuando reciba una señal tiene que ejecutar una accion.
 Antes de que entre en pausa necesito que llame a la funcion sigaction, que es la que me permite decirle que tiene que hacer cuando llegue la señal.
 Para esa funcion necesito declarar una estructura tipo sigaction que llamaré sign
 Declarar todos sus campos a cero para evitar basura en las zonas de memoria, llamo a memset.
 El unico campo que necesito inizializar es sa_sigaction que es el que indica a que funcion hay que llamar "handle_sigusr1" 
 Con esas variables declaradas, puedo llamar a la funcion sigaction, pasandole lso argumentos que necesita.
 señal " SIGUSR1", donde estan los campos de la estructura, pongo NULL en el tercer parametro para indicar que no voy a usarla.
 Este argumento es opcional, es solo para guardar la configuracion anterior de la señal.
 Llamamos a getpid paara que nos de el pid y nos los printee.
 A partir de aqui ya puede el server irse a dormir.
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>


void handle_sigusr1(int sig, siginfo_t* siginfo, void *context)
{
    (void)context; 
    (void)siginfo;

    if (sig == SIGUSR1)        printf("Hola");
}

int main() 
{
    struct sigaction sign;
    memset(&sign, 0, sizeof(sign)); 
    sign.sa_sigaction = handle_sigusr1;

    if (sigaction(SIGUSR1, &sign, NULL) == -1) 
        return -1;
    printf("Server PID: %d\n", getpid());

    int signal_count = 0;
    while (signal_count < 5)
    {
        pause();
        printf("Parece que he recibido una señal!! Seguiré durmiendo un rato más\n");
        signal_count++;
    }
    printf("Has llegado al limite de las 5 señales\n");
    return 0;
}    
