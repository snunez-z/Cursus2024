/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:41:39 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 19:06:03 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t len)
{
	size_t	index;
	size_t	equals;
	size_t	s2_len;

	if (*needle == 0)
		return ((char *)haystack);
	s2_len = ft_strlen(needle);
	index = 0;
	while (index < len && *haystack != '\0')
	{
		equals = ft_strncmp (haystack, needle, s2_len);
		if (equals == 0)
		{
			if ((len - index) < s2_len)
				return (0);
			else
				return ((char *)haystack);
		}
		haystack++;
		index++;
	}
	return (0);
}
