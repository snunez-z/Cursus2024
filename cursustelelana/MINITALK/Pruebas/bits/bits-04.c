#include <stdio.h>

void store_bits(char ch, int *buffer)
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

// Cambia el main para llamar a store_bits con los caracteres del primer
// parámetro que reciba el programa (es decir argv[1])
// Por ejemplo: Si argv[1] es "Hola", tiene que llamar a store_bits con
// la 'H', luego con la 'o', luego la 'l', luego la 'a' y finalmente el '\0'
int main(int argc, char **argv)
{
    int bits[8];

    return (0);
}

