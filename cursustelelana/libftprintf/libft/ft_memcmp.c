/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:02:13 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/23 10:06:47 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void	*s1, const void	*s2, size_t n)
{
	size_t			index;
	unsigned char	*aux1;
	unsigned char	*aux2;
	int				result_cmp;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		result_cmp = *aux1 - *aux2;
		if (result_cmp != 0)
		{
			return (result_cmp);
		}
		else
		{
			aux1++;
			aux2++;
			index++;
		}
	}
	return (0);
}
