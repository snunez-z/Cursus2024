/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:40:02 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/20 13:43:27 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "../libft.h"

void	t_len_bigger_size(char	*dest, const char *src, size_t size)
{
	int		max_chars_to_copy;
	size_t	length;
	int		index;

	length = ft_strlen(dest);
	max_chars_to_copy = (size - length) - 1;
	dest = dest + length;
	index = 0;
	while (index < max_chars_to_copy)
	{
		*dest = *src;
		src++;
		dest++;
		index++;
	}
	*dest = '\0';
}

size_t	ft_strlcat(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	length;
	size_t	total_length;

	length = ft_strlen(dst);
	total_length = length + ft_strlen(src);
	if ((length) >= dstsize)
		return (dstsize + ft_strlen (src));
	if (total_length >= dstsize)
	{
		t_len_bigger_size(dst, src, dstsize);
		return (total_length);
	}
	dst = dst + length;
	while (*src != '\0')
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return (total_length);
}
/*
int	main(void)
{

	char	dest[10];
	int	length ;


		ft_strlcpy (dest, "Hola", 5);
	   	length = ft_strlcat (dest, "", 2);
		printf("%d = %s\n", length, dest);

		ft_strlcpy (dest, "hola", 5);
   		length = ft_strlcat (dest, "", 2);
		printf("%d = %s\n", length, dest);
		
		ft_strlcpy (dest, "Hola", 5);
   		length = ft_strlcat (dest, "Sushi", 10);
		printf("%d = %s\n", length, dest);

		ft_strlcpy (dest, "Hola", 5);
   		length = ft_strlcat (dest, "Sushi", 4);
		printf("%d = %s\n", length, dest);

	   return (0);
}*/
