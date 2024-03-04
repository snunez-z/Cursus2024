/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:39:37 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 18:48:27 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void	*dst, const void	*src, size_t len)
{
	int			index;
	char		*dest1;
	const char	*src1;

	dest1 = (char *) dst;
	src1 = (const char *) src;
	if ((dest1 > src1) && (src1 + len) > dest1)
	{
		index = len - 1;
		
		while (index >= 0)
		{
			dest1 [index] = src1 [index];
			index--;
		}
		return (dst);
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
