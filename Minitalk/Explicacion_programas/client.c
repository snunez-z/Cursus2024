/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:10:08 by snunez-z          #+#    #+#             */
/*   Updated: 2024/06/25 08:42:10 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"

static void	byte_to_signals(char byte, int *buffer, int start_index)
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
			buffer[start_index] = SIGUSR1;
		else
			buffer[start_index] = SIGUSR2;
		start_index++;
		mask = mask / 2;
		bit_index++;
	}
}
static int *message_to_signals(const char *message)
{
	size_t	num_bytes;
	int	num_bits;
	int	*buffer;
	size_t	byte_index;
	int	start_index;

	num_bytes = ft_strlen (message) + 1;
	num_bits = num_bytes * 8;
	buffer = malloc (num_bits * sizeof(int));
	if (buffer == NULL)
	{
		free (buffer);
		return (NULL);
	}
	byte_index = 0;
	start_index = 0;
	while (byte_index < num_bytes)
	{
		byte_to_signals(message[byte_index], buffer, start_index);
		byte_index++;
		start_index = start_index + 8;
	}
	return (buffer);
}

int	main(int argc, char **argv)
{
	int		pid;
	int		*signals;
	int		num_signals;
	size_t	num_bytes;
	int		result_send_signals;
	int		index;

	if (argc < 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		return (-1);
	signals =message_to_signals(argv[2]);
	num_bytes = ft_strlen (argv[2]) + 1;
	num_signals = num_bytes * 8;
	index = 0;
	while ( index < num_signals)
	{
		result_send_signals = kill (pid, signals[index]);
		if (result_send_signals == -1)
			return (-1);
		index++;
		usleep (500);
	}
	free (signals);
	return (0);
}	
