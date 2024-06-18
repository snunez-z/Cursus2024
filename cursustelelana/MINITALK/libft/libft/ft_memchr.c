/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:48:18 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 17:37:50 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*aux;
	unsigned int	casted_c;

	casted_c = (unsigned int)c;
	if (casted_c > 255)
		casted_c = (casted_c % 256);
	aux = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (*aux == casted_c)
		{
			return ((void *)aux);
		}
		else
		{
			aux++;
		}
		index ++;
	}
	return ((void *)0);
}
/*
int	main(void)
{
	char	*str;

	str = ft_memchr("Hola", 'l', 4);
	printf("Puntero a str %ld : resultado %ld\n",(long) "Hola", (long)str);
	str = ft_memchr("Hola", 'l' + 256, 3);
	printf("Puntero a str %ld : resultado %ld\n",(long) "Hala", (long)str);
	str = ft_memchr("Hola", 'l', 2);
	printf("Puntero a str %ld : resultado %ld\n",(long) "Hola", (long)str);
	return (0);
	char bytes[] = {
	0xca, 0x66, 0xd9, 0x5f, 0xbc, 0xa2 , 0xd4, 0xdb, 0xb2, 0xc2 , 
	0x84, 0x7b, 0xab, 0x43, 0xa1, 0xf0, 0xe5, 0x38, 0x40, 0x67 , 
	0xf9, 0x59, 0xf9, 0x0e, 0x81, 0x1d , 0xf1, 0xb4, 0xee, 0xf2, 
	0xa4, 0xb9,	0x58, 0x7d, 0x18, 0x14 , 0x1f, 0xec, 0xf0, 0xd1,
   	0xaf, 0x74, 0x4d, 0x5a, 0xb7, 0xee , 0x4a, 0x9c
	};
	void* result = ft_memchr(bytes, 240, 33);
	printf("%ld / %ld\n", (long)bytes, (long)result);
}*/
