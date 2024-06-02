/* En este ejercicio el server usa la funcion usleep y esta funcion duerme en funcion de un tiempo, interrumpida cuando le llega una señal
  o cuando pasan el tiempo predefinido y sigue ejecutando lo que hay debajo,en este caso printea en que señal esta.
  Esto nos ayuda a detectar errores. Con el pause, nunca se ejecturaa lo de despues, si no ha habido uan interrumpicion por señal recibida.
  de la recepción de una señal como pause(), 
  por lo tanto el control del numero de señales recibida, ahora lo tiene que hacer la funcion hanndler_sigur1. 
  Para que haya una comunicacion entre las dos funciones "Handler" y el main, usamos la variable global count, que es la que va a definir el numero de señales
  y tanto el main como el handler la van a usar como referente.
  Se duerme solo para no gastar recursos de la CPU.
  El main esta funcionando de forma sincrona y a la vez el handler esta funcionando de forma asincrona respecto al main, solo cuando se envia una señal, 
  el main sigue en su sincronicidad pero al mismo tiempo se ejecuta el handler.
  El main esta vivo pero en letargo, el handler esta muerto, cuando el cliente que es un tercero, manda la señal,
  el sistema operativo llama al handler y el main cuando le toque despertar (segun el tiempo) se da cuenta que ha cambiado el signal_count y lo printea y luego duerme.*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>:w

int signal_count = 0;

void handle_sigusr1(int sig, siginfo_t* siginfo, void *context)
{
    (void)context; 
    (void)siginfo;

   	if (sig == SIGUSR1)
		printf("Hola");

    signal_count++;
}

int main() 
{
    struct sigaction sign;
    memset(&sign, 0, sizeof(sign)); 
    sign.sa_sigaction = handle_sigusr1;

    if (sigaction(SIGUSR1, &sign, NULL) == -1) 
        return -1;
    printf("Server PID: %d\n", getpid());

    while (signal_count < 5)
    {
        usleep(30000000);
        printf("Por ahora he recibido %d señales. Seguiré durmiendo un rato más\n", signal_count);
    }
    printf("Has llegado al limite de las 5 señales\n");
    return 0;
}    
