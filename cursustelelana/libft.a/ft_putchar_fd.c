/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:10:21 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/18 18:04:00 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
int	main(void)
{
	int	stdout_fd;

	stdout_fd = 1;
	ft_putchar_fd ('S', stdout_fd);
	ft_putchar_fd ('U', stdout_fd);
	ft_putchar_fd ('S', stdout_fd);
	ft_putchar_fd ('A', stdout_fd);
	ft_putchar_fd ('N', stdout_fd);
	ft_putchar_fd ('A', stdout_fd);
	ft_putchar_fd ('\n', stdout_fd);
	return (0);
}*/
