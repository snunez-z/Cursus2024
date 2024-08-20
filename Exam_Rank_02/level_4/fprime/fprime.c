/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:46:14 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 14:46:19 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void fprime (int num)
{
	int	factor;

	if (num == 1)
	{
		printf("1");
		return;
	}

	factor = 2;
	while(num > 1)
	{
		while (num % factor == 0)
		{
			printf("%d",factor);
			num = num/factor;
			if (num > 1)
				printf("*");
		}
		factor ++;
	}
}

int	main(int argc, char **argv)
{
	int	num;
	
	if(argc == 2)
	{	
		num = atoi (argv[1]);
		fprime(num);
	}	
	printf("\n");
	return (0);
}
