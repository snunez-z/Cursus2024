/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:21:19 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/02 09:23:00 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/
#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*len;

	len = ft_itoa(n);
	if (len)
		ft_putstr_fd(len, fd);
	free(len);
}
/*
int	main(void)
{
	int	stdout_fd;

	stdout_fd = 1;
	ft_putnbr_fd(555, stdout_fd);
	printf("\n");
	ft_putnbr_fd(-555, stdout_fd);
	printf("\n");
	ft_putnbr_fd(-1247000, stdout_fd);
	printf("\n");
	ft_putnbr_fd(0, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(35, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(2147483647, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(-2147483648, stdout_fd);
	printf("\n");
	return (0);
}*/
