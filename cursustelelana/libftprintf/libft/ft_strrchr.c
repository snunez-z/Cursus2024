/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:21:40 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 18:59:15 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	char	*last_ocurrence;

	if (c > 255)
		c = (c % 256);
	last_ocurrence = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			last_ocurrence = (char *)s;
		}
		s++;
	}
	if (last_ocurrence != 0)
		return (last_ocurrence);
	else if (c == '\0')
		return ((char *)s);
	else
		return (0);
}
/*
int	main(void)

{
	char	*result;

	result = ft_strrchr("Hola", 'o');
	printf("%s\n", result);
	result = ft_strrchr("Hola", 'e');
	if (result == 0)
		printf("No se ha encontrado\n");
	result = ft_strrchr("Hola", 'o' + 256 );
	printf("%s\n", result);
	result = ft_strrchr("Hola", '\0');
	if (result == 0)
		printf("No se ha encontrado\n");
}*/
