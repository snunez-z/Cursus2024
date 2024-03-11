#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int printf_convertion_x (va_list args, int count)
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
		free (str);
		if(w_check < 0)
			return (-1);
	}
	return (count);
}
