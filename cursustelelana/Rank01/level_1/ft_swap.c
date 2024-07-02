/*Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.
Escribe una funcion que intercambie el contenido de dos enteros cuyos punteros son pasados como parametros

Your function must be declared as follows:

void	ft_swap(int *a, int *b);*/

void ft_swap (int *a, int *b)
{
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
}

#include <stdio.h>
int main (void)
{
    int a = 13;
    int b = 15;
   
    ft_swap (&a, &b);
    printf("Ahora a vale = %d ", a);
    printf ("Ahora b vale = %d,", b);
    return (0);
}
