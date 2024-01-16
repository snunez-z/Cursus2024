/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:39:37 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/12 17:01:08 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void	*dest, const void	*src, size_t len)
{
	size_t		index;
	char		*dest1;
	const char	*src1;

	dest1 = (char *) dest;
	src1 = (const char *) src;
	if ((dest1 > src1) && (dest1 - src1) < (int) len)
	{
		index = len - 1;
		while (index > 0)
		{
			dest1 [index] = src1 [index];
			index--;
		}
		return (dest);
	}
	else
	{
		ft_memcpy(dest, src, len);
	}
	return (dest);
}
/*
int	main(void)
{
	char	buffer [100] = "Hola";
	char	dest [20] = "";
	char	*src = &(buffer [0]);
	char	*dest1 = &(buffer [2]);

	ft_memmove(dest, buffer, 5);
	printf("%s\n", dest);
	ft_strlcpy(buffer, "Hola Caracola", 14);
	ft_memmove(dest1, src, 7);
	printf("%s\n", buffer);
	ft_strlcpy(buffer, "Hola Caracola", 14);
	src = &(buffer[2]);
	dest1 = &(buffer[0]);
	ft_memmove(dest1, src, 7);
	printf("%s\n", buffer);
	ft_strlcpy(buffer, "Hola Caracola", 14);
	src = &(buffer[2]);
	dest1 = &(buffer[0]);
	ft_memmove(dest1, src, 0);
	printf("%s\n", buffer);
	return (0);
}*/
