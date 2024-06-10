#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main(int argc, char **argv)
{
    int *bits;
    int num_chars;
    int char_index;
    int bit_size;
    
    if (argc < 2 )
        printf("usage %s <file> \n", argv [0]);
    
    num_chars = strlen (argv[1] + 1);
    bit_size = num_chars * 8;
    bits = malloc ((bit_size)* sizeof(int));
    if(bits == NULL)
        return(1);
    char_index = 0;
    while (char_index < num_chars)
    {
        store_bits (argv[1][char_index], bits);
        char_index++;
    }    
    print_bits(bits);
    free (bits);
    return (0);
}