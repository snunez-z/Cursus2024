/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:45:27 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/15 13:23:26 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n = n / 2;
	if (n == 1)
		return (1);
	else 
		return (0);
}
/* main to check teh function
#include <stdio.h>

int	main(void)
{
	int	result;
	
	result = is_power_of_2 (32);
	printf("%d\n", result);
}
