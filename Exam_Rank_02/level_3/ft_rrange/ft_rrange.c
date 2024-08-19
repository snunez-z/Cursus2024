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

#include <stdlib.h>

int *ft_rrange(int start, int end)
{
	long num_numbers;
	long i;
	int *numbers;
	int value;

	if(start <= end)
		num_numbers = (long)end - (long)start +1;
	else
		num_numbers = (long)start - (long)end +1;

	numbers = (int *) malloc(num_numbers * sizeof(int));
	if (numbers == NULL)
		return(NULL);

	i = 0;
	value = end;
	while(i < num_numbers)
	{
		numbers[i] = value;
		if (start <=end)
			value--;
		else
			value++;
		i++;
	}
	return(numbers);
}

/*to check the function
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
