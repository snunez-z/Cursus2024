/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:50:34 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 17:07:36 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
	int	mask ;
	int	bits_char;

	mask = 128;
	bits_char = 0;
	while (bits_char < 8)
	{
		if ((octet & mask) == 0)
			write (1, "0", 1);
		else 
			write (1, "1", 1);
		bits_char++;
		mask = mask / 2;
	}
}	

#include <stdio.h>

int	main(void)
{
	
	print_bits (2);
	return (0);
}
