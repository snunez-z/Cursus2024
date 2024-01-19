/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:41:44 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/19 08:32:39 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char	*str, int fd)
{
	int	index;

	index = 0;
	while (str [index] != 0)
	{
		ft_putchar_fd (str [index], fd);
		index++;
	}
}
/*
int	main(void)
{
	int	stdout_fd;

	stdout_fd = 1;
	ft_putstr_fd("Susana Nunez Zamora", stdout_fd);
	write (1, "\n", 1);
	return (0);
}*/
