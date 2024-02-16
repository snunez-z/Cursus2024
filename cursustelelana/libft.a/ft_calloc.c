/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 08:10:21 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/12 10:17:40 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
//#include <stdio.h>

void	*ft_calloc(size_t quantity, size_t size_of_each_element)
{
	size_t	total_bytes;
	void	*result;

	total_bytes = quantity * size_of_each_element;
	result = malloc(total_bytes);
	if (result)
		ft_bzero(result, total_bytes);
	return (result);
}
/*
int	main(void)
{
	int	*numbers;
	int	index;

	numbers = ft_calloc (100, sizeof (int));
	index = 0;
	while (index < 100)
	{
		printf("%d", numbers[index]);
		index++;
	}
	return (0);
}*/
