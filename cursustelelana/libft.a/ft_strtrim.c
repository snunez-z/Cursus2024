/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:30:17 by snunez-z          #+#    #+#             */
/*   Updated: 2024/01/18 12:46:41 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(const char	*str, const char *set)
{
	char	*result;
	size_t	left_index;
	size_t	right_index;
	size_t	size;

	left_index = 0;
	while (str[left_index] != 0 && ft_strchr(set, str [left_index]) != 0)
	{
		left_index++;
	}
	right_index = ft_strlen (str)-1;
	while (right_index > left_index && ft_strchr (set, str[right_index]) != 0)
	{
		right_index--;
	}
	size = (right_index - left_index + 2);
	result = ((char *) malloc (size));
	ft_strlcpy (result, str + left_index, size);
	return (result);
}

int	main(void)
{
	char	*result;

	result = ft_strtrim ("SUSANA NUNEZ", "USAZE");
	printf("%s\n", result);
	result = ft_strtrim (" HOLA ", " ");
	printf("%s\n", result);
	result = ft_strtrim (" H ", " ");
	printf("%s\n", result);
	return (0);
}
