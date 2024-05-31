/* que hace ? El programa server es un proceso que esta siendo ejecutado por la computadora.
Este programa server lo que hace es esperar dormido y cuando le llega una señal SIGUSR1, ejecuta algo.
En ese caso printea Hola y sigue durmiendo.
como lo hace? 
Una señal es enviarle hacer algo a un proceso y para ello se necesita el PID de ese proceso, en este caso el PID del server.
En este caso cuando le llegue una señal va a escrirbir hola. 
El programa main es sincrono, que se ejecuta una orden detras de otra de forma sincrona, como un scrit. 
En este caso hay una parte que es sincrona y otrra que es asincrona. Se va a ejecturar cuando le llegue un señal, pero el server no sabe cuando.

Necesitamos una estructura sigaction a la vamos a llamar sa. La estructura sigaction tiene muchos parametros pero nosotos vamos a usar el handler que es 
el que le dice que accion tomar al server cuando reciba la señal.

struct sigaction {
                  void (*sa_handler)(int);
                  void (*sa_sigaction)(int, siginfo_t *, void *);
                  sigset_t sa_mask;
                  int sa_flags;
                  void (*sa_restorer)(void);
Vamos a usar la funcion sigacion para la accion y los parametros que recibe por contrato son la señal SIGUSR1, el valor de los parametros de la struct sa y el NULL.
el tercer parametro es la posib le accion que se hubiese prefijado anteriormente. En nuestro caso como e sninguna seria NULL, pero podria darse el caso que hibiese
una y para no perderla se guardaria en ese parametro.
Getpid() = es uan  funcion para que te de el numero PID de ese programa.
pause = deja en pausa, dormido el programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

void handle_sigusr1(int sig, siginfo_t *siginfo, void *context)
{
    (void)context; 
    (void)siginfo;
    if (sig == SIGUSR1)
        printf("Hola");
 
}

int main() 
{
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa)); 
    sa.sa_sigaction = handle_sigusr1;
    if (sigaction(SIGUSR1, &sa, NULL) == -1) 
        return (-1);
    printf("Server PID: %d\n", getpid());
    
    while (1) 
       pause();
      
    return 0;
}

