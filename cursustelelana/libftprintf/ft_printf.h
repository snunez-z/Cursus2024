#ifndef LIBFTPRINTF_H

#define LIBFTPRINTF_H

int     ft_printf(const char *format, ...);
char	*ft_utoa(unsigned int	n);
char	*ft_htoa(unsigned long	n);
char	*ft_htoa_lower(unsigned long n);

int     ft_putchar_printf(char	c);
int	    ft_putstr_printf(const char	*str);

#endif
