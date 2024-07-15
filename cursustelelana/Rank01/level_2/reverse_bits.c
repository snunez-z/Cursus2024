/*Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
 */

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
