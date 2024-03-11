
#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int printf_convertion_s(va_list args, int count)
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
