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

typedef struct s_server
{
	int num_signal; 
	char signals_received [8]; 
}	t_server;

t_server signal_control;

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
void handler_sigusr1 (int sign, siginfo_t *siginfo, void *context) 
{
   char byte;
      
   (void) context;
   (void)siginfo; 
   
   if (sign == SIGUSR1)
      signal_control.signals_received [signal_control.num_signal] = '0';
   else 
      signal_control.signals_received [signal_control.num_signal] = '1';
   signal_control.num_signal++;
   
   if (signal_control.num_signal == 8)
   {
      byte = ft_btoi (signal_control.signals_received);
      if (byte == '\0')
         write(1, "\n", 1);
      else
	     write(1, &byte, 1);
      signal_control.num_signal = 0;
   }
   kill(siginfo->si_pid, SIGUSR1);
}       

int main()
{
   struct sigaction sa;
   int   sig_S1;
   int   sig_S2;

   signal_control.num_signal = 0;

   ft_memset (&sa, 0, sizeof(sa)); 
   sa.sa_sigaction = handler_sigusr1; 
   sa.sa_flags = SA_SIGINFO; 
   sig_S1 = sigaction (SIGUSR1, &sa, NULL);
   sig_S2 = sigaction (SIGUSR2, &sa, NULL);
   if (sig_S1 == -1 || sig_S2 == -1)
      return (-1);
   ft_printf("Server PID: %d\n", getpid());

   while (1)
      pause();
   return(0);
}
