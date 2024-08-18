/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:56:45 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:56:48 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.*/

#include <stdio.h>
#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	long num_numbers;
	long i = 0;
	int *numbers;

	if(start <= end)
		num_numbers = (long)end - (long)start +1;
	else
		num_numbers = (long)start - (long)end +1;

	printf("la longitud es %ld\n", num_numbers);

	numbers = (int *) malloc(num_numbers * sizeof(int));
	if (numbers == NULL)
		return(NULL);
	while(i < num_numbers)
	{
		if (start <=end)
		{
			numbers[i] = end;
			printf("la posicion %ld, es %d\n", i, end);
			end--;
			i++;
		}
		else
		{
			numbers[i] = end;
			printf("la posicion %ld, es %d\n", i, end);
			end++;
			i++;
		}
	}
	return(numbers);
}

/*
int main()
{
	int start = 2147483647;
	int end= -2147483647;
	int *result;

	result = ft_rrange(start, end);
	return(0);
}*/
/*
 #include <stdio.h>
 int	main(void)
{
 	int start = -2147483648;
 	int end = 2147483647;
	int *prueba = ft_rrange(start, end);
	int i = 0;

 	while (i < 3)
 		printf("%d |", prueba[i++]);
 	return (0);
 }*/
