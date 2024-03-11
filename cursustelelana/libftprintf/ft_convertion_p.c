#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int printf_convertion_p (va_list args, int count)
{
	void	*p;
	char	*str;
	int		w_check;
    
	p = va_arg(args, void *);
	if(p == 0)
	{
		w_check = ft_putstr_printf ("(nil)");
		if (w_check < 0)
			return (-1);
		count = count + 5;
	}
	else 
	{
		w_check = ft_putstr_printf("0x");
		if (w_check < 0)
			return (-1);
		str = ft_htoa_lower((unsigned long)p);
		if (str)
		{		
			count = count + 2 + ft_strlen (str);
			w_check = ft_putstr_printf(str);
			free (str);
			if (w_check < 0)
				return (-1);
		}	
	}
	return (count);
}
