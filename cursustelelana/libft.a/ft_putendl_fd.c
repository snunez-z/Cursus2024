/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 08:10:56 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/23 09:55:31 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void	ft_putendl_fd(char	*str, int fd)
{
	ft_putstr_fd (str, fd);
	ft_putchar_fd ('\n', fd);
}
/*
int	main(void)
{
	int	stdout_fd;

	stdout_fd = 1;
	ft_putendl_fd ("Susana Nunez Zamora", stdout_fd);
	ft_putendl_fd ("Archivo encriptado", stdout_fd);
	return (0);
}*/
