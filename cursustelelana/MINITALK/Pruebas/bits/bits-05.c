#include <stdio.h>
#include <string.h>

// Modifica esta función para que, en lugar de guardar los bits siempre desde
// el índice cero, los guarde desde el indice que se pasa en "start_index"
void store_bits(char ch, int *buffer, int start_index)
{
    int mask = 128;
    int index = 0;
    while (index < 8)
    {
        int bit = (ch & mask);
        if (bit == 0)
            buffer[index] = 0;
        else
            buffer[index] = 1;

        index++;
        mask = mask / 2;
    }
}

// Modifica esta función para que en lugar de mostrar 8 elementos del array, muestre
// tantos elementos como se indica en "num_bits"
void print_bits(int *buffer, int num_bits)
{
    int n = 0;
    while (n < 8)
    {
        printf("%d", buffer[n]);
        n++;
    }
    printf("\n");
}

// Aquí no tienes nada que hacer. Sólo entender cómo hago para calcular el tamaño del
// array que necesito y cómo voy rellenando de 8 en 8
int main(int argc, char **argv)
{
    int *bits;
    int bit_index;
    int bits_size;
    int char_index;
    int num_chars;

    if (argc < 2)
    {
        printf("Dime una palabra, payo!\n");
        return (1);
    }

    // Un carácter más, porque también vamos a convertir a bits el \0
    num_chars = strlen(argv[1]) + 1;
    // 8 bits por carácter
    bits_size = (num_chars * 8);
    bits = malloc(bits_size * sizeof(int));
    if (bits == NULL)
    {
        printf("Pon más memoria a tu PC, so rata\n");
        return (1);
    }

    // Vamos carácter a caracter... que para el array es ir de 8 en 8
    bit_index = 0;
    char_index = 0;
    while(char_index < num_chars)
    {
        store_bits(argv[1][char_index], bits, bit_index);
        char_index++;
        bit_index = bit_index + 8;
    }

    // Vamos a pintar los bits tosjuntos
    print_bits(bits, bits_size);

    // Higiene
    free(bits);
    return (0);
}

