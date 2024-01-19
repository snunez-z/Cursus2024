#include <unistd.h>

void    ft_printf_alphabet(void)
{
    char alpha;

    alpha = 'a';
    while (alpha < 'z')
    {   
        write(1, &alpha, 1);
        alpha++;
    }
}

int main(void)
{   
    ft_printf_alphabet ();
    return (0);
}
