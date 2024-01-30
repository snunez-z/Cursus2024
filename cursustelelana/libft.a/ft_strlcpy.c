/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:19:05 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/30 14:31:22 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/
#include "libft.h"

size_t	ft_strlcpy(char	*dest, const char	*src, size_t size)
{
	size_t	index;

	index = 0;
	if (src[index] == '\0')
	{
		dest[index] = '\0';
		return (0);
	}
	if (size == 0)
		return (ft_strlen (src));
	while (src[index] != '\0' && index < (size -1))
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	while (src[index] != '\0')
		index++;
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	buffer[0];
 	int		len;

	len = ft_strlcpy (buffer, "Hola", 3);
	printf ("%d\n", len);
	printf("%s", buffer);
	return (0);
}*/
