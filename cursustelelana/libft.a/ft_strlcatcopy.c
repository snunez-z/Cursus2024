/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:40:02 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/30 16:09:50 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char	*dest, const char	*src, size_t size)
{
	size_t	length;

	length = ft_strlen(dest);
	dest = dest + length;
	while (*src != '\0' && length < (size - 1))
	{
		*dest = *src;
		src++;
		dest++;
		length++;
	}
	*dest = '\0';
	return (length + ft_strlen(src));
}

int	main(void)
{
	char	* d1;
	char	*d2;
	int		len;
	
	d1 = "pqrstuvwwxyz";
	d2 = "abcd";
	len = 1;

	ft_strlcat(d1 , d2, len);
	printf("%d\n", len);
	return (0);
}	

	
	
	
	
/*	
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
