/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:21:48 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 17:13:15 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
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
