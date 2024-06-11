#include <stdio.h>

// Haz esta función que recibe una cadena de caracteres con un número
// en decimal, por ejemplo "576" y retorne el número como int
int sushi_atoi(const char *num)
{
}

// Haz esta función que recibe una cadena de caracteres con un número
// en hexadecimal, por ejemplo "FF" y retorne el número como int (para
// el ejemplo de "FF" tiene que retornar 255)
int sushi_htoi(const char *num)
{
}

int main(int argc, char **argv)
{
    int num;

    num = sushi_atoi("576");
    printf ("Si sale 576, es que está bien: %d\n", num);
    num = sushi_htoi("FF");
    printf ("Si sale 255, es que está bien: %d\n", num);
    return (0);
}

