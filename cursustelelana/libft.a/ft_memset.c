/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:41:47 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/02 10:25:52 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void	*src, int c, size_t n)
{
	size_t	index;
	char	*temp;

	temp = (char *) src;
	index = 0;
	while (index < n)
	{
		*temp = c;
		temp++;
		index++;
	}
	return (src);
}
/*
int	main(void)
{
	char	str1[5] = "Hola";
	char	str2[5] = "1234";

	printf("%s\n", ft_memset(str1, 34, 3));
	printf("%s\n", ft_memset(str2, 97, 3));
}*/
