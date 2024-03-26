#include <sdtio.h>

static char give_me_one_char()
{
    // Haz esta función que retorne un carácter cada vez de la cadena de caracteres
    // "Hola Sushi"
    // Es decir:
    // * La primera vez que se llame, tiene que retornar la 'H'
    // * La segunda vez, la 'o'
    // * La tercera vez, la 'l'
    // Así sucesivamente
}

int main(void)
{
    // Si has hecho bien la función, estos printf's deberían sacar "Hola"
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
}

