/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:55:33 by snunez-z          #+#    #+#             */
/*   Updated: 2024/09/10 11:23:45 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


