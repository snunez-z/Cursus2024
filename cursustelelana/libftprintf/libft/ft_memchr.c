/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:48:18 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/20 14:13:17 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*aux;
	unsigned int	casted_c;

	casted_c = (unsigned int)c;
	if (casted_c > 255)
		casted_c = (casted_c % 256);
	aux = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (*aux == casted_c)
		{
			return ((void *)aux);
		}
		else
		{
			aux++;
		}
		index ++;
	}
	return ((void *)0);
}
