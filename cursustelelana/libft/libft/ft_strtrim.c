/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:30:17 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 18:04:29 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "../libft.h"

char	*ft_strtrim(char const	*s1, char const	*set)
{
	char	*result;
	int		left_index;
	int		right_index;
	size_t	size;

	left_index = 0;
	while (s1[left_index] != 0 && ft_strchr(set, s1 [left_index]) != 0)
	{
		left_index++;
	}
	right_index = ft_strlen (s1)-1;
	while (right_index > left_index && ft_strchr (set, s1[right_index]) != 0)
	{
		right_index--;
	}
	size = (right_index - left_index + 2);
	result = ((char *) malloc (size));
	if (result)
		ft_strlcpy (result, s1 + left_index, size);
	return (result);
}
/*
int	main(void)
{
	char	*result;

	result = ft_strtrim ("SUSANA NUNEZ", "USAZE");
	printf("%s\n", result);
	result = ft_strtrim (" HOLA ", " ");
	printf("%s\n", result);
	result = ft_strtrim (" H ", " ");
	printf("%s\n", result);
	result = ft_strtrim ("", "");
	printf("%s\n", result);
	return (0);
}
*/
