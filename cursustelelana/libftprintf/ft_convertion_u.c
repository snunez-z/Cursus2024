#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int printf_convertion_u(va_list args, int count)
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
		free(str);
		if (w_check < 0)
			return (-1);
	}
	return (count);
}
