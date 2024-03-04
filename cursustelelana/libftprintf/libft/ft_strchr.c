/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:19:25 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/20 13:57:34 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	if (c > 255)
		c = (c % 256);
	while (*s != '\0')
	{
		if (*s != c)
			s++;
		else
			return ((char *)s);
	}
	if (c == '\0')
		return ((char *)s);
	else
		return (0);
}
