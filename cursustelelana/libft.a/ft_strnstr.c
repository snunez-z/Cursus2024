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
//#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(char	*s1, char	*s2, size_t n)
{
	size_t	index;
	size_t	equals;
	size_t	s2_len;

	if (*s2 == 0)
		return (s1);
	s2_len = (size_t)ft_strlen(s2);
	index = 0;
	while (index < n && *s1 != '\0')
	{
		equals = ft_strncmp (s1, s2, s2_len);
		if (equals == 0)
		{
			if ((n - index) < s2_len)
				return (0);
			else
				return (s1);
		}
		s1++;
		index++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*result;

	result = ft_strnstr("Hola buena amiga", "buen", 12);
	printf("%s\n", result);
	result = ft_strnstr("Hola buena amiga", "", 100);
	printf("%s\n", result);
	result = ft_strnstr("Hola buena amiga", "ola", 3);
	printf("%ld\n",(long) result);
	result = ft_strnstr("Hola buena amiga", "Hola buena amiga", 16);
	printf("%s\n", result);
}*/
