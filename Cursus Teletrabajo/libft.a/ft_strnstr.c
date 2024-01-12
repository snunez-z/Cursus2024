/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:41:39 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/11 18:40:48 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(char	*s1, char	*s2, size_t n)
{
	size_t	equals;

	while (*s1 != 0)
	{
		equals = ft_strncmp (s1, s2, n);
		if (equals == 0)
		{
			return (s1);
		}
		s1++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*result;

	result = ft_strnstr("Hola buena amiga", "Buen", 4);
	printf("%s\n", result);
	result = ft_strnstr("Hola buena amiga", "Bu", 2);
	printf("%s\n", result);
	result = ft_strnstr("Hola buena amiga", "ola", 3);
	printf("%s\n", result);
	result = ft_strnstr("Hola buena amiga", "Hola buena amiga", 16);
	printf("%s\n", result);
}*/
