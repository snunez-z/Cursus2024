/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:24:25 by snunez-z          #+#    #+#             */
/*   Updated: 2024/06/24 14:25:23 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"
#include "minitalk_bonus.h"

t_client	g_sig_cont;

static void	byte_to_signals(char byte, int start_index)
{
	int	mask;
	int	bit_index;
	int	bit;

	mask = 128;
	bit_index = 0;
	while (bit_index < 8)
	{
		bit = (byte & mask);
		if (bit == 0)
			g_sig_cont.signals[start_index] = SIGUSR1;
		else
			g_sig_cont.signals[start_index] = SIGUSR2;
		start_index++;
		mask = mask / 2;
		bit_index++;
	}
}

static void	message_to_signals(const char *message)
{
	int		num_bytes;
	int		byte_index;
	int		start_index;

	num_bytes = ft_strlen (message) + 1;
	g_sig_cont.num_signals = num_bytes * 8;
	g_sig_cont.signals = malloc (g_sig_cont.num_signals * sizeof(int));
	if (g_sig_cont.signals == NULL)
	{
		free (g_sig_cont.signals);
		return ;
	}
	byte_index = 0;
	start_index = 0;
	while (byte_index < num_bytes)
	{
		byte_to_signals(message[byte_index], start_index);
		byte_index++;
		start_index = start_index + 8;
	}
}

void	handler_sigusr1(int sign, siginfo_t *siginfo, void *context)
{
	(void)sign;
	(void)context;
	if (g_sig_cont.signal_index >= g_sig_cont.num_signals)
		return ;
	usleep(10);
	if (kill(siginfo->si_pid, g_sig_cont.signals[g_sig_cont.signal_index]) < 0)
	{
		ft_printf("Error signal to server PID %d\n", siginfo->si_pid);
		exit(-1);
	}
	g_sig_cont.signal_index++;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int								pid;

	if (argc < 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		return (-1);
	ft_memset (&sa, 0, sizeof(sa));
	sa.sa_sigaction = handler_sigusr1;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) < 0)
		return (-1);
	message_to_signals(argv[2]);
	g_sig_cont.signal_index = 1;
	if (kill(pid, g_sig_cont.signals[0]) < 0)
	{
		free (g_sig_cont.signals);
		return (-1);
	}
	while (g_sig_cont.signal_index < g_sig_cont.num_signals)
		pause ();
	free (g_sig_cont.signals);
	return (0);
}
