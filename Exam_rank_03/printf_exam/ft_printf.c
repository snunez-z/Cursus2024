/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:01:26 by snunez-z          #+#    #+#             */
/*   Updated: 2025/02/17 14:32:41 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	put_string(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string != '\0')
	{
		write(1, string++, 1);
		(*length)++;
	}
}

void	put_digit(long long int number, int base, int *length)
{
	char	*hexadecimal = "0123456789abcdef";

	if (number < 0)
	{
		number = number * -1;
		write(1, "-", 1);
		*length = *length + 1;
	}
	if (number >= base)
		put_digit((number / base), base, length);
	write(1, hexadecimal + (number % base), 1);
	*length = *length + 1;
}

int	ft_printf(const char *format, ...)
{
	int length = 0;

	va_list	next_arg;
	va_start(next_arg, format);

	while (*format != '\0')
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(next_arg, char *), &length);
			else if (*format == 'd')
				put_digit((long long int)va_arg(next_arg, int), 10, &length);
			else if (*format == 'x')
				put_digit((long long int)va_arg(next_arg, unsigned int), 16, &length);
		}
		else
		{
			write(1, format, 1);
			length++;
		}
		format++;
	}
	va_end(next_arg);
	return (length);
}

int	main(void)
{
	int n;
	int length;
	char *null;

	null = NULL; 
	length = 0;
	n = ft_printf ("NULL %s NULL\n", null);
	put_digit (n, 10, &length);
	put_string("\n", &length);
	n = ft_printf(" Hola soy %s y tengo %d años\n", "Sushi", 53);
	put_digit(n, 10, &length);
	n = ft_printf("%d %d %d %d %d\n", -300, 300, -2147483648, 2147483647, 0);
	put_digit(n, 10, &length);
	put_string ("\n", &length);
	n = ft_printf("%x %x %x %x en hexa\n", 15, 56, 0, 255);
	put_digit (n, 16, &length);
} 
