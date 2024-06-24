#include <stdio.h>
#include <ctype.h>

// Haz esta función que recibe una cadena de caracteres con un número
// en decimal, por ejemplo "576" y retorne el número como int
int sushi_atoi(const char *num)
{
       char digit;
       int  value;
       
       value = 0;
        while (*num != '\0')
       {
           digit = (*num - '0');
           value = (value * 10) + digit;
           num++;
       }
       return (value);
}

// Haz esta función que recibe una cadena de caracteres con un número
// en hexadecimal, por ejemplo "FF" y retorne el número como int (para
// el ejemplo de "FF" tiene que retornar 255)
int sushi_htoi(const char *num)
{
    char    digit;
    int value;
       
    value = 0;
    while (*num != '\0')
    {
        if (isdigit (*num))
        {
            digit = (*num - '0');
            value = (value * 16) + digit;
        }
        else if (*num >= 'A' && *num <= 'F')
        {
            digit = (*num - 'A') + 10; // que es donde empieza la primera letra 
            value = (value *16) + digit;
        }
        num++;
    }
    return (value);
}
int sushi_btoi(const char *num)
{
    char    digit;
    int value;
       
    value = 0;
    while (*num != '\0')
    {
        
            digit = (*num - '0');
            value = (value * 2) + digit;
            num++;
    }
    return (value);
}
int main(int argc, char **argv)
{
    int num;

    num = sushi_atoi("576");
    printf ("Si sale 576, es que está bien: %d\n", num);
    num = sushi_htoi("FF");
    printf ("Si sale 255, es que está bien: %d\n", num);
    num = sushi_btoi ("01000001");
    printf ("Si sale 65, es que está bien: %d\n", num);
    return (0);
}
