/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:41:01 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 19:40:45 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t n)
{
	size_t		index;
	char		*dest1;
	const char	*src1;

	dest1 = (char *) dst;
	src1 = (const char *) src;
	index = 0;
	if (dest1 == 0 && src1 == 0)
		return (0);
	while (index < n)
	{
		dest1 [index] = src1 [index];
		index++;
	}
	return (dst);
}
