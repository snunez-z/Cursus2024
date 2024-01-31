/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:19:25 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/18 11:48:41 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/

char	*ft_strchr(const char	*str, int c)
{
	if (c > 255)
		c = (c % 256);

	while (*str != '\0')
	{
		if (*str != c)
			str++;
		else
			return ((char *)str);
	}
	if (c == '\0')
		return ((char *)str);
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
