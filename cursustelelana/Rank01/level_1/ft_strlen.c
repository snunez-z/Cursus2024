/*Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the length of a string.

Your function must be declared as follows:

int	ft_strlen(char *str);*/

int ft_strlen (char *str)
{
    int index;

    index = 0;
    while (str[index] != '\0')
    {
        index++;
    }
    return (index);
}

#include <stdio.h>

int main(void)
{
    printf("%d\n", ft_strlen ("Hola amiga"));
    return (0);
}  
