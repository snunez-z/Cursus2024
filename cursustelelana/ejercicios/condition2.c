#include <stdio.h>

int main(void)
{
    int num1;
    int num2;
    int num3;

    // Vamos a pedir tres números
    printf("Dime un número: ");
    scanf("%d", &num1);
    printf("Dime un número: ");
    scanf("%d", &num2);
    printf("Dime un número: ");
    scanf("%d", &num3);

    // Si alguno de los es menor que cero, saca un mensaje
    // que diga "al menos uno de los números es negativo"

    if (num1 < 0 || num2 <0 || num3 <0)
        printf("Al menos uno de los numeros es negativo");
    return (0);
}
