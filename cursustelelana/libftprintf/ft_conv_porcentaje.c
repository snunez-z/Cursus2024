#include "ft_printf.h"
#include <stdarg.h>

int printf_conv_porcentaje(int count)
{
	int	w_check;
	
	w_check = ft_putchar_printf('%');
	if (w_check < 0)
		return (-1);
	count++;
	return (count);
}
