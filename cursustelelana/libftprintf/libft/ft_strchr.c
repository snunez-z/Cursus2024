/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:19:25 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 17:31:45 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
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
/*
int	main(void)
{
	char	*result;

	result = strchr ("SONORo", 'o' + 256);
	printf("%s\n", result);
	result = ft_strchr ("SONORo", 'o' + 256);
	printf("%s\n", result);
	
	result = ft_strchr ("SONORo", 'c');
	if (result == 0)
			printf("No encontrado\n");
	result = strchr ("SONORo", 'c');
	if (result == 0)
			printf("No encontrado\n");

	result = ft_strchr ("SONORo", '\0');
	printf("%s\n", result);
	result = strchr ("SONORo", '\0');
	printf("%s\n", result);
	
	return (0);
}*/
