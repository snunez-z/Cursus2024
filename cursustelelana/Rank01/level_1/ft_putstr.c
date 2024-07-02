/*Write a function that displays a string on the standard output.
Escribe una funcion que muestre una cadena en la salida estandar

The pointer passed to the function contains the address of the string's first
character.
El puntero de la funcion contiene a direccion del primer carcater de la cadena.
Your function must be declared as follows:

void	ft_putstr(char *str);*/


#include <unistd.h>

void    ft_putstr (char *str)
{
    while (*str != '\0')
    {
        write (1, str, 1);
        str++;
    }
}

int main (void)
{
   
    ft_putstr ("Hola buena amiga");
    write (1, "\n", 1);
}
