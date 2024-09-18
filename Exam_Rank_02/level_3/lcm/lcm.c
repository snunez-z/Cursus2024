/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:57:59 by snunez-z          #+#    #+#             */
/*   Updated: 2024/09/17 08:49:01 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
        unsigned int    number;

        if (a == 0 || b == 0)
                return (0);
        if (a > b)
                number = a;
        else
                number = b;
        while (1)
        {
                if (number % a == 0 && number % b == 0)
                        return (number);
                number++;
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
