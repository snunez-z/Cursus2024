
/*3. Modifica tu server para acabe después de haber recibido una señal SIGUSR1*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void handler_sigusr1 (int sign, siginfo_t *siginfo, void *context)
{
   (void) context;
   if (sign == SIGUSR1)
   {
       printf("SIGUSR1 received from PID %d\n", siginfo->si_pid);
   }
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
   pause();
   return(0);
}
