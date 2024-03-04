/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:07:57 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 17:53:54 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	size;
	char			*copy;

	size = ft_strlen(s1) + 1;
	copy = malloc(size * sizeof(char));
	if (copy)
		ft_strlcpy(copy, s1, size);
	return (copy);
}
