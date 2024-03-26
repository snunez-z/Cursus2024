#include <sdtio.h>

static char give_me_one_char()
{
    // Igual que la anterior PERO si se piden más caracteres de los que hay
    // (es decir, si se llama a give_me_one_char más veces que caracteres hay
    // en "Hola Sushi"), tiene que retornar '*'
}

int main(void)
{
    // Si has hecho bien la función, estos printf's deberían sacar "Hola Sushi**"
    // Los dos asteriscos tienen que salir porque llamamos 12 veces a give_me_one_char
    // pero "Hola Sushi" sólo tiene 10 caracteres, así es que, para las dos últimas
    // llamadas, give_me_one_char retorna '*'
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
    printf("%c", give_me_one_char());
}

