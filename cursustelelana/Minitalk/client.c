/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:10:08 by snunez-z          #+#    #+#             */
/*   Updated: 2024/06/18 11:01:53 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_server
{
	int    *signals;
	int     num_signals;
	int     signal_index;
}	t_server;

t_server	signal_control;

static void byte_to_signals(char byte, int start_index) 
{
    int mask = 128;
    int bit_index = 0;
    int bit;
    
    while (bit_index < 8)
    {
        bit = (byte & mask);
        if (bit == 0)
            signal_control.signals[start_index] = SIGUSR1;
        else
            signal_control.signals[start_index] = SIGUSR2;

        start_index++;
        mask = mask / 2;
        bit_index++;
    }
}

static void message_to_signals(const char *message)
{
    int num_bytes;
    int byte_index;
    int start_index;
    
    num_bytes = ft_strlen (message) + 1;
    signal_control.num_signals = num_bytes * 8;
    signal_control.signals = malloc (signal_control.num_signals * sizeof(int));
    if (signal_control.signals == NULL)
	{
     	free (signal_control.signals);
	 	return;
	}
    byte_index = 0;
    start_index= 0;
    while (byte_index < num_bytes)
    {
        byte_to_signals(message[byte_index], start_index);
        byte_index++;
        start_index = start_index + 8;
    }
}   

void handler_sigusr1 (int sign, siginfo_t *siginfo, void *context) 
{
    (void)sign;
    (void)context;

    if (signal_control.signal_index >= signal_control.num_signals) 
		return;
    usleep(10); 
    if (kill(siginfo->si_pid, signal_control.signals[signal_control.signal_index]) < 0)
    {
        ft_printf("Error sending signal to server with PID %d\n", siginfo->si_pid);
        exit(-1);
    }
    signal_control.signal_index++;
}

int main(int argc, char **argv) 
{
    int     pid;
    struct sigaction sa;
     
    if (argc < 3 )
        return (1);
    pid =ft_atoi (argv[1]);
    if (pid == 0)
       return (-1);
    ft_memset (&sa, 0, sizeof(sa)); 
    sa.sa_sigaction = handler_sigusr1; 
    sa.sa_flags = SA_SIGINFO;
    if(sigaction (SIGUSR1, &sa, NULL) < 0)
       return (-1);
    message_to_signals (argv[2]);  
    signal_control.signal_index = 1;
    if (kill(pid, signal_control.signals[0]) < 0)
    {
        free (signal_control.signals);
        return (-1);
    }
    while (signal_control.signal_index < signal_control.num_signals) // No tiene signal_index++ porque lo tiene el handler de forma asincrona
        pause();
    free (signal_control.signals);
    return (0);
}