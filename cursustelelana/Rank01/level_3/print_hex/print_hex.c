/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:59:14 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:59:16 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	putnbr_base (int	num, int base)
{
	char conversion_table[] = "0123456789abcdef";
	char digit;

	digit = (num % base);
	if (num > base )
		putnbr_base(num / base, base);
	write (1 , &conversion_table[digit], 1);
}

int atoi(char *num)
{
	int result;
	result = 0;
	while (*num != 0)
	{
		result = (result * 10) + (*num - '0');
		num++;
	}
	return (result);
}

int main(int argc, char **argv)
{
	int num;
	num = atoi(argv[1]);
	putnbr_base(num, 16);
	write(1, "\n", 1);
}	

