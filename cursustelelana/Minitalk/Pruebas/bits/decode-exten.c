#include <stdio.h>
#include <string.h>

int convert_bits_chars (char *bits)
{
    int result;
    int index;
   
    result = 0;
    index = 0;
    while (index < 8)
    {
        result = result * 2;
        result = result + (bits [index] - '0');
        index++;
    }
    printf("El número es %c\n", result);
    return (result);
} 
/*
int main (int argc, char **argv)
{
    char *bits;

    bits = argv[1];
    convert_bits_chars (bits);
    return (0);
} */  

int main (int argc, char **argv)
{
    char *bits;
    char *result;
  
    bits = argv [1];
    result = convert_bits_chars (bits);
    return (0);
}
