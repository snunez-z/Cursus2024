#include <unistd.h>

void    ft_is_negative(int  n)
{
    char valor;
    char ls;

    ls = '\n';

    if (n >= 0)
    {
        valor = 'P';
    }
    else if (n < 0)
    {
        valor = 'N';
    }
        write (1, &valor, 1);
        write (1, &ls, 1);
}

int main(void)
{
    ft_is_negative (2);
    ft_is_negative(-2);
    return (0);
}
