#include <unistd.h>
#include <stdarg.h>

void    put_string(char *str, int   *len)
{
    if(!str)
        str = "(null)";
    while(*str != '\0')
    {
        write(1, str, 1);
        str++;
        *len = *len + 1;
    }
}

void    put_digit(long long int number, int base, int *len)
{
    char    *hexadecimal = "0123456789abcdef";

    if(number < 0)
    {
        number = number * -1;
        write(1, "-", 1);
        *len = *len + 1;
    }
    if(number >=base)
        put_digit(number/base, base, len);
    write(1, hexadecimal + (number % base), 1);
    *len = *len +1;
}
int ft_printf(const char *format, ...)
{
    int len;
    va_list next_arg;
    va_start(next_arg, format);
    while(*format != '\0')
    {
        if(*format == '%' && (((*(format +1) == 's')) || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
        {
            format++;
            if(*format == 's')
                put_string(va_arg(next_arg, char*), &len);
            else if(*format == 'd')
                put_digit((long long int)va_arg(next_arg, int), 10, &len);
            else if(*format == 'x')
                put_digit((long long int)va_arg(next_arg, unsigned int), 16, &len);
        }
        else
        {
            write(1, format, 1);
            len++;
        }
        format++;
    }
    return(len);
}

int main(void)
{
    int len;
    char    *null;
    int n;

    len = 0;
    null = NULL;

    n = ft_printf("NULL %s NULL\n", null);
    put_digit (n, 10, &len);
    put_string("\n", &len);

    n = ft_printf("Hola soy %s y tengo %d años \n", "Susana", 54);
    put_digit (n, 10, &len);
    put_string("\n", &len);

    n = ft_printf("%d %d %d %d %d\n", -300, -300, 0, -2147483648, 2147483647);
    put_digit (n, 10, &len);
    put_string("\n", &len);

    n = ft_printf("%x %x %x %x %x\n", 15, 255, 0, -2147483648, 2147483647);
    put_digit (n, 16, &len);
    put_string("\n", &len);


}