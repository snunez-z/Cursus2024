#include <stdio.h>

int main(void)
{
    int numbers[5];
    int index;
    int is_negative;

    // Vamos a pedir cinco números
    index = 0;
    while (index < 5)
    {
        printf("Dime un número:");
        scanf("%d", &numbers[index]);
        index++;
    }
    index = 0;
    while (index < 5)
    {
        if (numbers[index] < 0)
        {
            is_negative = 1;
        }
    index++;
    }
    printf("Al menos uno de los numeros es negativo");
    return (0);
}
    // Si alguno de los es menor que cero, saca un mensaje
    // que diga "al menos uno de los números es negativo"

