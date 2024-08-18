#include <stdio.h>

int main(void)
{
    int numbers[10];
    int size;
    int index;
    int is_negative;

    // Vamos a pedir el número de números (valga la renfunfancia)
    // que vamos a pedir
    printf("Cuántos números quieres pedir (1-10)? ");
    scanf("%d", &size);

    // Vamos a pedir los números
    index = 0;
    while (index < size)
    {
        printf("Dime un número: ");
        scanf("%d", &numbers[index]);
        index++;
    }
    // Si alguno de los es menor que cero, saca un mensaje
    // que diga "al menos uno de los números es negativo"
    index = 0;
    while (index < size)
    {
        if (numbers[index] < 0)
        {
           is_negative = 1;
        }
    index ++;
    }
    if (is_negative)
        printf ("Al menos uno es negativo");
    else
        printf (" son todos positivos");
return (0);
}