/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:19:05 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/12 13:46:42 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char	*dest, const char	*src, size_t size)
{
	size_t	index;

	index = 0;
	while (src [index] != 0 && index < (size - 1))
	{
		dest[index] = src[index];
		index++;
	}
	dest [index] = 0;
	while (src [index] != 0)
	{
		index++;
	}
	return (index);
}
/*
int	main(void)
{
	char	buffer [8];
	int		lenght;

	lenght = ft_strlcpy(buffer, "Hola", 8);
	printf("%s\n", buffer);
	lenght = ft_strlcpy(buffer, "Torrelodones", 8);
	printf("%s\n", buffer);
	return (0);
}*/
