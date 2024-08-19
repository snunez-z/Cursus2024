/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:57:59 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:58:02 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int mult;

	if (a == 0 || b == 0)
		return (0);
	mult = 1;
	while((a * mult) % b != 0)
		mult++;
	return (a*mult);
}
/* To check the function 
#include <stdio.h>
int	main(void)
{
	printf("lcm(12,15) = %d\n", lcm (12, 15));
	printf("lcm(2,2) = %d\n", lcm (2, 2));
	printf("lcm(10,100) = %d\n", lcm (10,100));
	printf("lcm(0,0) = %d\n", lcm (0, 0));
	printf("lcm(11,50) = %d\n", lcm (11, 50));
	printf("lcm(120,15) = %d\n", lcm (120,15));
	printf("lcm(15,120) = %d\n", lcm (15,120));
	return (0);
}*/
