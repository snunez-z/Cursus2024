#include <stdio.h>

// Este ejercicio va de que no todo es pintar en pantalla.
// De hecho, la mayoría de las funciones sólo trabajan con datos, sin pintar nada
// En nuestro caso, queremos una función que transforme un char en bits que va
// a guardar en un array.

// Implementa esta función:
// La función recibe un char y tiene que GUARDAR sus bits de DERECHA A IZQUIERDA
// en el array "buffer" que se pasa como parámetro
// OJO!!!! NO TIENES QUE PINTARLOS! SÓLO GUARDARLOS EN EL ARRAY
// Por ejemplo, si recibe una 'A', que es un 65, que en binario es 01000001,
// tiene que guardar 01000001 en el array
// PISTA: Recuerda: Para guardar los bits de DERECHA A IZQUIERDA, tienes que usar
//                  una máscara que empiece en 128 y, en lugar de mover la máscara
//                  a la derecha multiplicando por 2, la mueves a la izquierda
//                  dividiendo entre 2. Y usar la operación & (AND a nivel de bits)
void store_bits(char ch, int *buffer)
{
}

void print_bits(int *buffer)
{
    int n = 0;
    while (n < 8)
    {
        printf("%d", buffer[n]);
        n++;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    int bits[8];

    store_bits('H', bits);
    print_bits(bits);

    store_bits('o', bits);
    print_bits(bits);

    store_bits('l', bits);
    print_bits(bits);

    store_bits('a', bits);
    print_bits(bits);

    store_bits('\0', bits);
    print_bits(bits);

    return (0);
}

