/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_result_push_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:42:56 by snunez-z          #+#    #+#             */
/*   Updated: 2025/01/09 14:03:05 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>
#include "ft_printf.h"
#include "push_swap.h"
#include "libft.h"

static int	read_line(int fd, char *buffer, size_t bytes_max)
{
	char	ch;
	int		read_result;
	size_t	index;

	index = 0;
	read_result = read(fd, &ch, 1);
	while (read_result == 1 && index < bytes_max && ch != '\n')
	{
		buffer[index] = ch;
		index++;
		read_result = read (fd, &ch, 1);
	}
	buffer [index] = '\0';
	if (read_result < 0 || index >= bytes_max)
		return (-1);
	return (index);
}

int	read_result_push_swap(t_stack_list **a, t_stack_list **b)
{
	int		read_result;
	char	buffer[10];

	read_result = read_line (0, buffer, 9);
	while (read_result > 0)
	{
		if (exec_one_comd(buffer, a, b) == 0)
			return (0);
		read_result = read_line (0, buffer, 9);
	}
	return (read_result);
}
