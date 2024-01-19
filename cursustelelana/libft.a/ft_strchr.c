/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:19:25 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/18 11:48:41 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char	*ft_strchr(const char	*str, int c)
{
	while (*str != 0)
	{
		if (*str != c)
		{
			str++;
		}
		else
		{
			return ((char *)str);
		}
	}
	return (0);
}
/*
int	main(void)
{
	char	*result;

	result = ft_strchr ("SONORo", 'o');
	printf("%s\n", result);
	result = ft_strchr ("SONORo", 'O');
	printf("%s\n", result);
	result = ft_strchr ("SONORo", 'I');
	if (result == 0)
	{
		printf(" No se ha encontrado el caracter en esa cadena");
	}
	return (0);
}*/
