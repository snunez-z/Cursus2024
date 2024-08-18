#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char  signals_received [8]; // donde guardar las señales recibidas
int   num_signal = 0; // donde ir contando 

int ft_btoi(const char *num)
{
    char    digit;
    int value;
    int index;
       
    index = 0;
    value = 0;
    while (index < 8)
    {
            digit = (*num - '0');
            value = (value * 2) + digit;
            num++;
            index++;
    }
    return (value);
}
void handler_sigusr1 (int sign, siginfo_t *siginfo, void *context) // bucle asincrono - el concpeto es igual que un bucle while pero como no sabemos cuando vamos a recbir la señal.Se ejecuta una vez cada vez que recibes la señal cada vez.
{
   char ch;
   (void) context;
   printf("Signal received from pid %d\n", siginfo->si_pid);

   if (sign == SIGUSR1)
      signals_received [num_signal] = '0';
   else 
      signals_received [num_signal] = '1';
   num_signal++;
   
   if (num_signal == 8)
    {
      // Aunque retorna int, yo se que he decificado un número
      // entre 0 y 255, así es que me cabe en un char
     ch = ft_btoi (signals_received);
	  printf( "%c", ch);
      num_signal = 0;
      if (buffer [buffer_index] == '\0')
	  {
         printf("%s\n", buffer);
	  	 buffer_index = 0;
	  }
	  else
         buffer_index++;
    }
   if (kill(siginfo->si_pid, SIGUSR1) < 0)
      printf("Signal no processed\n");
   printf(" Signal processed from pid %d\n", siginfo->si_pid);   
}       

int main()
{
   struct sigaction sa;
   int   sig_S1;
   int   sig_S2;

   memset (&sa, 0, sizeof(sa)); 
   sa.sa_sigaction = handler_sigusr1; //donde, a que funcion hay que llamar cuando llegue la señal
   sa.sa_flags = SA_SIGINFO; // Definimos como queremos que nos llegue la señal, con info o sin info
   sig_S1 = sigaction (SIGUSR1, &sa, NULL);
   sig_S2 = sigaction (SIGUSR2, &sa, NULL);
   if (sig_S1 == -1 || sig_S2 == -1)
      return (-1);
   printf("Server PID: %d\n", getpid());
   while (1)
      pause();
   return(0);
}
