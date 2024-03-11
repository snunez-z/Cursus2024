#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int printf_convertion_c (va_list args, int count)
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
