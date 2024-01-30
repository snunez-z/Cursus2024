/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:46:32 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/30 17:04:52 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char	*str, unsigned int start, size_t len)
{
	char	*sub;
	
	if (start > ft_strlen((int)(str))) 
		sub [0] = '\0';	
	if ((start + len) > ft_strlen (str))
		sub[0] = '\0';
	
	sub = (char *)malloc ((len +1) * sizeof(char));
	if (sub == 0)
	{
		return (0);
	}
	ft_strlcpy (sub, (str + start), (len + 1));
	return (sub);
}

int	main(void)
{
	char	*new_str;

	new_str = ft_substr ("Susana Nunez Zamora", 7, 5);
	printf("%s\n", new_str);
	new_str = ft_substr ("Susana Nunez Zamora", 10, 6);
	printf("%s\n", new_str);
	new_str = ft_substr ("Susana Nunez Zamora", 2, 10);
	printf("%s\n", new_str);
	free (new_str);
	return (0);
}
