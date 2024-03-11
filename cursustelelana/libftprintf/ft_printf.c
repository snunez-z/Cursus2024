/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:33:10 by snunez-z          #+#    #+#             */
/*   Updated: 2024/03/06 14:27:32 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

static int printf_convertion(va_list args, const char *format, int count)
{
	if(*(format + 1) == 's')
		count = printf_convertion_s(args, count);
	else if(*(format + 1) == 'd' || *(format + 1) == 'i')
		count = printf_convertion_d_i(args, count);
	else if(*(format + 1) == 'c')
		count = printf_convertion_c (args, count);	
	else if(*(format + 1) == '%')
		count = printf_conv_porcentaje(count);
	else if(*(format + 1) == 'u')
		count = printf_convertion_u (args, count);
	else if(*(format + 1) == 'x')
		count = printf_convertion_x(args, count);	
	else if(*(format + 1) == 'X')
		count = printf_convertion_X(args, count);
	else if(*(format + 1) == 'p')
		count = printf_convertion_p(args, count);
	return (count);

}

int ft_printf(const char *format, ...)
{
	int	count;
	va_list args;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			count++;
			format++;
		}
		else
		{ 
			count = printf_convertion (args, format, count);
			if (count < 0)
				return (-1);
			format = format + 2;
		}
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
	int n;

	n = ft_printf ("NULL %s NULL\n", (char *)NULL);
	n = printf ("NULL %s NULL\n",(char *) NULL);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd("\n", 1);
	n = ft_printf(" Hola soy %s y tengo %u años\n", "Sushi", 53);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n = ft_printf("%d %d %d %i %i\n", -300, 300, -2147483648, 2147483647, 0);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n = ft_printf("El caracter a copiar es %c %c %c\n", 'c', 'S', '9', '0');
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n = ft_printf("%u %u %u %u %u\n", -300, 300, -2147483648, 2147483647, 0);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n= ft_printf(" El %%20 de las ventas de este mes se han dado en la categoria de fosforos\n");
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n = ft_printf("%X %X %X %X en hexa\n", 0, 35, 154678, 255);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n = ft_printf("%x %x %x %x en hexa\n", 15, 56, 0, 255);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n = ft_printf ("%p\n", (void *) -1);
	n = printf ("%p\n", (void *)-1);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n = ft_printf ("%p %p\n", 0, 0);
	n = printf ("%p %p\n", 0, 0);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd("\n", 1);
	n = ft_printf ("%p %p\n", 1, 1);
	n = printf ("%p %p\n", 1, 1);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd("\n", 1);
	n = ft_printf ("Tengo %i anos\n", 53);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n= ft_printf("La variable n se encuentra en la posicion de memoria %p\n", &n);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
}*/
