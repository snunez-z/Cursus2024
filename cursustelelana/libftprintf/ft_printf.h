#ifndef LIBFTPRINTF_H

#define LIBFTPRINTF_H

#include <stdarg.h>

int	ft_printf(const char *format, ...);
char	*ft_utoa(unsigned int n);
char	*ft_htoa(unsigned long n);
char	*ft_htoa_lower(unsigned long n);
int	ft_putchar_printf(char c);
int	ft_putstr_printf(const char *str);
int	printf_convertion_s(va_list argas, int count);
int	printf_convertion_d_i(va_list args, int count);
int	printf_convertion_c(va_list args, int count);
int	printf_conv_porcentaje(int count);
int	printf_convertion_u(va_list args, int count);
int	printf_convertion_x(va_list args, int count);
int	printf_convertion_X(va_list args, int count);
int	printf_convertion_p(va_list args, int count);

#endif
