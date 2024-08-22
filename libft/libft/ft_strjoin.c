/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:50:32 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/22 12:37:19 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "../libft.h"
#include <stdlib.h>

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
	if (!sub)
	{
		return ((int)NULL);
	}
	ft_strlcpy (sub, s1, len1 +1);
	ft_strlcat (sub, s2, t_size);
	return (sub);
}
/*
int	main(void)
{
	char	*result;

	result = ft_strjoin("Susana", "Nuñez");
	printf("%s\n", result);
	free (result);
	return (0);
}*/
