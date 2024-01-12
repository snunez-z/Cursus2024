/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:21:40 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/10 14:38:10 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

char	*ft_strrchr(char	*s1, int c)
{
	char	*last_ocurrence;

	last_ocurrence = 0;
	while (*s1 != '\0')
	{
		if (*s1 == c)
		{
			last_ocurrence = s1;
		}
		s1++;
	}
	return (last_ocurrence);
}
/*
int	main(void)

{
	char	*result;

	result = ft_strrchr("Hola", 'o');
	printf("%s\n", result);
	result = ft_strrchr("Hola", 'e');
	printf("%s\n", result);
}*/
