/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:40:02 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/17 17:04:19 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char	*dest, const char	*src, size_t size)
{
	size_t	length;

	length = ft_strlen(dest);
	dest = dest + length;
	while (*src != 0 && length < (size - 1))
	{
		*dest = *src;
		src++;
		dest++;
		length++;
	}
	*dest = 0;
	return (length + ft_strlen(src));
}
/*
int	main(void)
{
	char	buffer [10];
	int		length;

	length = ft_strlcat(buffer, "Hola", 10);
	printf("%d = %s\n", length, buffer);
	length = ft_strlcat(buffer, "buena", 10);
	printf("%d = %s\n", length, buffer);
	length = ft_strlcat(buffer, "amiga", 10);
	printf("%d = %s\n", length, buffer);
	return (0);
}*/
