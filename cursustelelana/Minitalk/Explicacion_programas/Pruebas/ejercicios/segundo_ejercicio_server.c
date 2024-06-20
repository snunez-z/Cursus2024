
/*Modifica tu server para que pueda recibir señales SIGUSR1
   Cuando reciba una, tiene que mostrar el mensaje
   "SIGUSR1 received from PID <el pid del remitente de la señal>"
   
   Modifica el cliente para que envíe una señal SIGUSR1 al PID que le han pasado
   como parámetro

   La vas a cagar en este (en la parte del server). Cuando veas que no te funciona
   dímelo*/
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
