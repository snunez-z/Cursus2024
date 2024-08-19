/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:56:27 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/15 13:26:54 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int	start, int end)
{
	int	*numbers;
	long	num_numbers;
	int 	inc;
	long	index;

	if (start > end)
	{
		num_numbers = ((long)start - (long)end) + 1; 
		inc = -1;
	}
	else
	{
		// Esto es para el corner case de que start sea MAS PEQUENIO que end
		num_numbers = ((long)end - (long)start) + 1; 
		inc = 1;
	}
	numbers = (int *) malloc (num_numbers * sizeof(int));
	if (numbers == NULL)
		return (NULL);
	index = 0;
	while (index < num_numbers)
	{
		numbers[index] = start;
		index++;
		start = start + inc;
	}
	return (numbers);	
}
/* To check the function
#include <stdio.h>

int	main(void)
{
	int	*numbers;
	int i;

	numbers = ft_range ( 7, 3);
	i = 0;
	while (i < 5 )
	{
		printf("%d\n", numbers [i]);
		i++;
	}
	return (0);
}*/
