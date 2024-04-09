#include <stdio.h>

int main(void)
{
    int numbers[10];
    int size;
    int index;

    // Vamos a pedir el número de números (valga la renfunfancia)
    // que vamos a pedir
    printf("Cuántos números quieres pedir (1-10)? ");
    scanf("%d", &size);

    // Vamos a pedir los números
    int index = 0;
    while (index < size)
    {
        printf("Dime un número: ");
        scanf("%d", &numers[index]);
        index++;
    }

    // MIENTRAS alguno de los es menor que cero, suma 1 a cada uno de
    // los números en el array

    return (0);
}
