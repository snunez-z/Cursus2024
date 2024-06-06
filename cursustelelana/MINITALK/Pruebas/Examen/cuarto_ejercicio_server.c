
/*Modifica tu server para que responda tanto a señales SIGUSR1 como a SIGUSR2
   Debes usar la misma función handler para las dos señales.
   En la función handler, que hasta ahora estabas poniendo "SIGUSR1 received from ..."
   cámbialo para que diga la señal recibida, es decir:
   "SIGUSR1/SIGUSR2 received from PID <el pid del remitente>"
   Debe mostrar SIGUSR1 o SIGUSR2 dependiendo que la que haya recibido

   Modifica tu cliente para que envíe una señal SIGUSR1 y luego una señal SIGUSR2
*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void handler_sigusr1 (int sign, siginfo_t *siginfo, void *context)
{
   (void) context;
   if (sign == SIGUSR1)
      printf("SIGUSR1 received from PID %d\n", siginfo->si_pid);
   else if (sign == SIGUSR2)
      	printf("SIGUSR2 received from PID %d\n", siginfo->si_pid);
   exit (0);
}  

int main()
{
   struct sigaction sa;
   memset (&sa, 0, sizeof(sa));
   sa.sa_sigaction = handler_sigusr1;
   sa.sa_flags = SA_SIGINFO;
   if (sigaction(SIGUSR1, &sa, NULL) == -1)
      return (-1);
   printf("Server PID: %d\n", getpid());
   while (1) 
       pause();
   return (0);
}
