#include <stdio.h>

// Implementa esta función:
// La función recibe un char y tiene que pintar sus bits de izquierda a derecha
// Por ejemplo, si recibe una 'A', que es un 65, que en binario es 01000001,
// tiene que pintar 10000010 (pintarlos de izquierda a derecha)
// Usa printf
// Después de pintarlos, tiene que pintar, tiene que pintar un salto de línea
// PISTA: Recuerda: Para pintar los bits de izquierda a derecha, tienes que usar
//                  una máscara que empiece en 1. Y usar la operación &
//                  (AND a nivel de bits)

void print_bits(char ch)
{
    int char_bits;
    int mask;
    
    char_bits = 0;
    mask = 1;
    while (char_bits < 8)
    {
        if ((ch & mask) == 0)
            printf("0");
        else 
            printf ("1");
        mask = mask * 2;
        char_bits++;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    print_bits('H');
    print_bits('o');
    print_bits('l');
    print_bits('a');
    print_bits('\0');
    return (0);
}

