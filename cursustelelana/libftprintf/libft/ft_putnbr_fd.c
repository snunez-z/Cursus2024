/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:21:19 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/12 11:14:52 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putnbr_without_sign(unsigned int n, int fd)
{
	char	digit;

	if (n == 0)
	{
		return ;
	}
	ft_putnbr_without_sign(n / 10, fd);
	digit = (n % 10) + '0';
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unsigned_n;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		unsigned_n = (n * -1);
	}
	else
		unsigned_n = n;
	ft_putnbr_without_sign(unsigned_n, fd);
}
