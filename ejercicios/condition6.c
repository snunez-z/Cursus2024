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

    // MIENTRAS alguno de los es menor que cero, suma 1 a cada uno de
    // los números en el array
index = 0;
while (index < size)
{
    if (numbers[index] < 0)
        is_negative = 1;
        if (is_negative)
        {
            index = 0;
            while (index < size)
            {
                numbers[index] = numbers[index] -1;
                index++;
            }
        }
    index++;
}
printf("Los nuevos valores son:");
index = 0;
while ( index < size)
{
    printf("%d ", numbers[index]);
    index++;
}
}

