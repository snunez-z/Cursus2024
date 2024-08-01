/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:52:31 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:52:34 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Your function must be declared as follows:

unsigned char	swap_bits(unsigned char octet);

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100
 */
unsigned char swap_bits (unsigned char octet)
{
	int	mask_and;
	int	mask_or;
	int	swap;
	int	index;
	unsigned int result;

	mask_and = 128;
	mask_or = 8;
    index = 0;
	result = 0;
	while (index < 4)
	{
		if ((octet & mask_and) != 0)
			result = result | mask_or;
		mask_and = mask_and / 2;
		mask_or = mask_or / 2;
		index++;
	}
	mask_and = 8;
	mask_or = 128;
	index = 0;
	while (index < 4)
	{
		if ((octet & mask_and) != 0)
			result = result | mask_or;
		mask_and = mask_and / 2;
		mask_or = mask_or / 2;
		index ++;
	}	
	return (result);
}

#include <stdio.h>

int	main(void)
{
	int result;

	result = swap_bits(65);
	printf("%u\n", result);		
	return (0);
}
