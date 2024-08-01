/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:55:33 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 12:55:36 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);*/

char to_lower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch - 'A') + 'a';
	return ch;
}

int	digit_to_value (char digit)
{
	int i;
	char conversion_table [] = "0123456789abcdef";
	
	i = 0;
	digit = to_lower(digit);
	while (conversion_table [i] != '\0')
	{
		if (digit == conversion_table [i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	value;
	int	i;

	if(str[0] == '-')
		i = 1;
	else
		i = 0;
	value = 0;
	while (str[i] != '\0')
	{
		value = (value * str_base) + digit_to_value (str [i]);
		i++;
	}
	if(str[0] == '-')
		value = value *-1;
	return (value);
}

#include <stdio.h>
int	main (void)
{
	int	value;

	value = ft_atoi_base ("-123", 4);
	printf ("%d\n", value);
	value = ft_atoi_base ("-123", 16);
	printf ("%d\n", value);
	value = ft_atoi_base ( "ff", 16);
	printf ("%d\n", value);
	value = ft_atoi_base ( "123", 5);
	printf ("%d\n", value);
	value = ft_atoi_base ( "123", 10);
	printf ("%d\n", value);
}


