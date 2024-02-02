/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:41:01 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/02 10:52:40 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void	*dest, const void	*src, size_t n)
{
	size_t		index;
	char		*dest1;
	const char	*src1;

	dest1 = (char *) dest;
	src1 = (const char *) src;
	index = 0;
	while (index < n)
	{
		dest1 [index] = src1 [index];
		index++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src [] = "Hola";
	char	dest [5] = "";

	printf("%s\n", ft_memcpy(dest, src, 5));
	printf("%s\n", dest);
	return (0);
}*/
