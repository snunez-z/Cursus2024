/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:42:38 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/11 19:19:06 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stddef.h>

int	ft_strncmp(char	*s1,	char*s2, size_t	n)
{
	size_t	index;
	int		result;
	unsigned char	*aux1;
	unsigned char	*aux2;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	index = 0;
	result = 0;
	while ((result == 0) && (*aux1 != '\0') && (*aux2 != '\0') && (index < n))
	{
		result = (*aux1 - *aux2);
		aux1++;
		aux2++;
		index++;
	}
	if ((result == 0) && (index < n))
	{
		result = (*aux1 - *aux2);
	}
	return (result);
}
/*
int	main(void)
{
	printf("%d\n", ft_strncmp("Hola", "Hola", 4));
	printf("%d\n", ft_strncmp("Hola", "holas", 4));
	printf("%d\n", ft_strncmp("Susana Nunez", "Susana Gonzalez", 12));
	printf("%d\n", ft_strncmp("Susana Gonzalez", "Susana Nunez", 4));
	printf("%d\n", ft_strncmp("Hola", "Hola", 3));
	printf("%d\n", ft_strncmp("01234", "01234", 4));
	printf("%d\n", ft_strncmp("012345", "0123", 4));
	return (0);
}*/
