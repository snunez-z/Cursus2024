/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:09:10 by snunez-z          #+#    #+#             */
/*   Updated: 2024/06/18 11:39:22 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_sig
{
	int num_signal; // donde ir contando
	char signals_received [8]; // donde guardar las señales recibidas
}	t_sig;

t_sig signal_control;

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
   (void)siginfo; 
   // ft_printf("Signal received from pid %d\n", siginfo->si_pid);

   if (sign == SIGUSR1)
      signal_control.signals_received [signal_control.num_signal] = '0';
   else 
      signal_control.signals_received [signal_control.num_signal] = '1';
   signal_control.num_signal++;
   
   if (signal_control.num_signal == 8)
   {
      // Aunque retorna int, yo se que he decificado un número
      // entre 0 y 255, así es que me cabe en un char
      ch = ft_btoi (signal_control.signals_received);
      if (ch == '\0')
         write(1, "\n", 1);
      else
	     write(1, &ch, 1);
      signal_control.num_signal = 0;
   }

   // Let's tell the client to send the next signal
   kill(siginfo->si_pid, SIGUSR1);
}       

int main()
{
   struct sigaction sa;
   int   sig_S1;
   int   sig_S2;

   signal_control.num_signal = 0;

   ft_memset (&sa, 0, sizeof(sa)); 
   sa.sa_sigaction = handler_sigusr1; //donde, a que funcion hay que llamar cuando llegue la señal
   sa.sa_flags = SA_SIGINFO; // Definimos como queremos que nos llegue la señal, con info o sin info
   sig_S1 = sigaction (SIGUSR1, &sa, NULL);
   sig_S2 = sigaction (SIGUSR2, &sa, NULL);
   if (sig_S1 == -1 || sig_S2 == -1)
      return (-1);
   ft_printf("Server PID: %d\n", getpid());

   while (1)
      pause();
   return(0);
}
