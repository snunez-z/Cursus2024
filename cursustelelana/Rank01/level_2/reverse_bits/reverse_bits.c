/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:51:08 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 17:58:39 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int		mask_cod;
	int		mask_dec;
	int		bits_char;
	unsigned char	byte;

	mask_cod = 128;
	mask_dec = 1;
	byte = 0;
	bits_char = 0;
	while (bits_char < 8)
	{
		if ((octet & mask_cod) != 0)
			byte = byte | mask_dec;
		bits_char++;
		mask_cod = mask_cod / 2;
		mask_dec = mask_dec * 2;
	}
	return (byte);
}

#include <stdio.h>
int	main(void)
{
	unsigned int byte;

	byte = reverse_bits (225);
	printf("%u\n", byte);
	return (0);
}
