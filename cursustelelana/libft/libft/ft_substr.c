/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:46:32 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 17:57:16 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include <stdlib.h>
#include "../libft.h"

char	*ft_substr(const char	*s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	s_len;

	s_len = (unsigned int) ft_strlen(s);
	if (start > s_len)
	{
		sub = (char *)malloc (1);
		if (sub)
			sub [0] = '\0';
		return (sub);
	}
	if ((start + len) > s_len)
	{
		sub = (char *)malloc (((s_len - start) + 1) * sizeof(char));
		if (sub)
			ft_strlcpy (sub, (s + start), ((s_len - start) + 1));
		return (sub);
	}
	sub = (char *)malloc ((len +1) * sizeof(char));
	if (sub)
		ft_strlcpy (sub, (s + start), (len + 1));
	return (sub);
}
/*
int	main(void)
{
	char	*new_str;

	new_str = ft_substr ("Susana", 8, 5);
	printf("%s\n", new_str);
	new_str = ft_substr ("Susana Nunez", 6, 20);
	printf("%s\n", new_str);
	new_str = ft_substr ("Susana Nunez Zamora", 2, 8);
	printf("%s\n", new_str);
	free (new_str);
	return (0);
}*/
