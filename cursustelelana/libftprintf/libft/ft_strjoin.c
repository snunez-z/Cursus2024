/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:50:32 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 17:59:57 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const	*s1, char const		*s2)
{
	char	*sub;
	size_t	len1;
	size_t	len2;
	size_t	t_size;

	len1 = ft_strlen (s1);
	len2 = ft_strlen (s2);
	t_size = (len1 + len2) + 1;
	sub = (char *) malloc (t_size);
	if (sub == 0)
	{
		return (0);
	}
	ft_strlcpy (sub, s1, len1 +1);
	ft_strlcat (sub, s2, t_size);
	return (sub);
}
