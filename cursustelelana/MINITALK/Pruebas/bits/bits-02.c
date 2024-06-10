#include <stdio.h>

// Implementa esta función:
// La función recibe un char y tiene que pintar sus bits de DERECHA A IZQUIERDA
// Por ejemplo, si recibe una 'A', que es un 65, que en binario es 01000001,
// tiene que pintar 01000001
// Usa printf
// Después de pintarlos, tiene que pintar, tiene que pintar un salto de línea
// PISTA: Recuerda: Para pintar los bits de DERECHA A IZQUIERDA, tienes que usar
//                  una máscara que empiece en 128 y, en lugar de mover la máscara
//                  a la derecha multiplicando por 2, la mueves a la izquierda
//                  dividiendo entre 2. Y usar la operación & (AND a nivel de bits)
void print_bits(char ch)
{
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

