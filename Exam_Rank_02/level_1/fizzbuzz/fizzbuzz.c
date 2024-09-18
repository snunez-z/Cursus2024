/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:10:05 by snunez-z          #+#    #+#             */
/*   Updated: 2024/09/18 13:40:18 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	write_numbers(int	num)
{
	char	numbers[10] = "0123456789";
	
	if(num > 9)
		write_numbers (num / 10);
	write (1,&numbers[num % 10], 1);
}

int	main(int argc, char	**argv)
{
	int	num;

	num = 1;
	while (num <= 100)
	{
		if (num % 15 == 0)
			write (1, "fizzbuzz", 8);
		else if (num % 3 == 0)
			write(1, "fizz", 4);
		else if (num % 5 == 0)
			write (1, "buzz",4);
		else
			write_numbers (num);
		num++;
		write (1, "\n", 1);
 	}
	return (0);
}	
