/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:24:25 by snunez-z          #+#    #+#             */
/*   Updated: 2024/06/25 16:47:48 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"
#include "minitalk_bonus.h"

t_client	g_sig_cont;

static void	send_next_signal(int pid)
{
	int	bit;

	int byte = g_sig_cont.message[g_sig_cont.byte_index];
	bit = (byte & g_sig_cont.mask);
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	g_sig_cont.mask = g_sig_cont.mask / 2;
	if (g_sig_cont.mask == 0)
	{
		if (byte == '\0')
			g_sig_cont.is_finished = 1;
		else
		{
			g_sig_cont.mask = 128;
			g_sig_cont.byte_index++;
		}
	}
}

void	handler_sigusr1(int sign, siginfo_t *siginfo, void *context)
{
	(void)sign;
	(void)context;
	if (g_sig_cont.is_finished)
		return ;
	usleep(10);
	send_next_signal(siginfo->si_pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

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
	g_sig_cont.mask = 128;
	g_sig_cont.byte_index = 0;
	g_sig_cont.message = argv[2];
	g_sig_cont.is_finished = 0;
	send_next_signal(pid);
	while (!g_sig_cont.is_finished)
		pause ();
	return (0);
}
