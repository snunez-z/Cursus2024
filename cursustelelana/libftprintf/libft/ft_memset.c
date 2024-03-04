/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:41:47 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 18:45:07 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	size_t	index;
	char	*temp;

	temp = (char *) b;
	index = 0;
	while (index < len)
	{
		*temp = c;
		temp++;
		index++;
	}
	return (b);
}
