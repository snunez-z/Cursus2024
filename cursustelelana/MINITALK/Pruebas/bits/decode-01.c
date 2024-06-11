#include <stdio.h>

int main(int argc, char **argv)
{
    int bits[8] = { 0, 1, 0, 0, 0, 0, 0, 1 };
    int resultado;
    int index;

    resultado = 0;
    index = 0;
    while ( index < 8)
    {
        resultado = resultado * 2 ;
        resultado = resultado + bits[index];
        index++;
    }
    printf("El número es %d\n", resultado);
    return (0);
}

int covert_bits_chars (char *bits)
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
    printf("El número es %d\n", result);
    return (result);
} 
 /*
int main (int argc, char **argv)
{
    
    int*array;

bits = strlen (argv[1]) + 1;
index = 0;
while (bits[index] < '\0')
{
    
    index++;
}

    printf("El número es %s\n", resultado);
    return (0);
}*/


