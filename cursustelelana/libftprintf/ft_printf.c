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

static int printf_convertion_s(va_list args, int count)
{
	char	*str;
	int		w_check;
	
	str = va_arg(args, char*);
	if(str == NULL)
	{
		w_check =ft_putstr_printf("(null)");
		if (w_check < 0)
			return (-1);
		count = count + 6;
	}
	else 
	{
		w_check = ft_putstr_printf(str);
		if (w_check < 0)
			return (-1);
		count = count + ft_strlen(str);
	}	
	return (count);
}	
static int	printf_convertion_d_i(va_list args, int count)
{
	int		c;
	char	*str;
	int		w_check;

	c = va_arg(args,int);
	str = ft_itoa (c);
	if(str) 
	{
		count = count + ft_strlen(str);
		w_check = ft_putstr_printf(str);
		if(w_check < 0)
			return (-1);
		free (str);
	}
		return (count);
}

static int printf_convertion_c (va_list args, int count)
{
	int		c;
	int		w_check;

	c = va_arg(args, int);
	w_check = ft_putchar_printf(c);
	if (w_check < 0)
		return (-1);
	count++;
	return (count);  
}

static int printf_conv_porcentaje(int count)
{
	int	w_check;
	
	w_check = ft_putchar_printf('%');
	if (w_check < 0)
		return (-1);
	count++;
	return (count);
}

static int printf_convertion_u(va_list args, int count)
{
	char			*str;
	unsigned int 	c;
	int				w_check;

	c = va_arg( args, unsigned int);
	str = ft_utoa(c);
	if (str)
	{
		count = count + ft_strlen(str);
		w_check = ft_putstr_printf(str);
		if (w_check < 0)
			return (-1);
		free(str);
	}
	return (count);
}

static int printf_convertion_x (va_list args, int count)
{
	char			*str;
	unsigned long 	ld;
	int				w_check;

	ld = va_arg (args, unsigned int);
	str = ft_htoa_lower(ld);
	if(str)
	{
		count = count + ft_strlen(str);
		w_check = ft_putstr_printf(str);
		if(w_check < 0)
			return (-1);
		free (str);
	}
	return (count);
}

static int printf_convertion_X (va_list args, int count)
{
	char			*str;
	unsigned long 	ld;
	int				w_check;

	ld = va_arg(args, unsigned int);
	str = ft_htoa(ld);
	if (str)
	{
		count = count + ft_strlen(str);
		w_check = ft_putstr_printf(str);
		if(w_check < 0)
			return (-1);
		free(str);
	}
	return( count);
}

static int printf_convertion_p (va_list args, int count)
{
	void	*p;
	char	*str;
	int		w_check;

	p = va_arg(args, void *);
	str = ft_htoa_lower((unsigned long)p);
	if (str)
	{
		count = count + 2 + ft_strlen (str);
		w_check = ft_putstr_printf("0x");
		if (w_check < 0)
			return (-1);
		w_check = ft_putstr_printf(str);
		if (w_check < 0)
			return (-1);
		free (str);
	}
	return (count);
}

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

	n = ft_printf ("%p\n", (void *) -1);
	n = printf ("%p\n", (void *)-1);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	
	n = ft_printf ("NULL %s NULL\n", NULL);
	n = printf ("NULL %s NULL\n", NULL);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd("\n", 1);
	n = ft_printf(" Hola soy %s y tengo %u años\n", "Sushi", 53);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n= ft_printf("Mi nombre tiene una %c\n", 'S');
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n = ft_printf ("Tengo %i anos\n", 53);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n= ft_printf(" El %%20 de las ventas de este mes se han dado en la categoria de fosforos\n");
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n = ft_printf("Hola soy %s y tengo %x años en hexadecimal\n", "Sushi", 53);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n = ft_printf("Hola soy %s y tengo %u años\n", "Sushi", 53);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n = ft_printf("Hola soy %s y tengo %X años en hexa\n", "Sushi", 255);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n = ft_printf("Hola soy %s y tengo %x años en hexa\n", "Sushi", 255);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n= ft_printf(" El %%20 de las ventas de este mes se han dado en la categoria de fosforos %d %% \n", 30);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
	n= ft_printf("La variable n se encuentra en la posicion de memoria %p\n", &n);
	ft_putnbr_fd (n, 1);
	ft_putstr_fd ("\n", 1);
}*/
