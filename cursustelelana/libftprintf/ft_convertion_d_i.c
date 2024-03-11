#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int	printf_convertion_d_i(va_list args, int count)
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
		free (str);
		if(w_check < 0)
			return (-1);
	}
	return (count);
}
