/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:50:32 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/18 14:41:00 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char	*str1, const char	*str2)
{
	char	*sub;
	size_t	len1;
	size_t	len2;
	size_t	t_size;

	len1 = ft_strlen (str1);
	len2 = ft_strlen (str2);
	t_size = (len1 + len2) + 1;
	sub = (char *) malloc (t_size);
	if (sub == 0)
	{
		return (0);
	}
	ft_strlcpy (sub, str1, len1 +1);
	ft_strlcat (sub, str2, t_size);
	return (sub);
}

int	main(void)
{
	char	*result;

	result = ft_strjoin("Susana", "Nuñez");
	printf("%s\n", result);
	free (result);
	return (0);
}
