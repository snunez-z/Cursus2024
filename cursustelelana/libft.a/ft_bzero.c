/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:21:48 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/12 10:43:24 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *src, size_t n)
{
	ft_memset(src, 0, n);
}
/*
int	main(void)
{
	char	src[5] = "Hola";
	char	src2[10] = "123456789";

	ft_bzero(src, 3);
	printf("%s\n", src);
	ft_bzero(src2, 3);
	printf("%s\n", src2);
}*/
