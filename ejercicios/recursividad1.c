
// Haz esta función. Lo que tiene que hacer es escribir (write) por pantalla (1)
    // la cadena de caracteres "str", pero tiene que hacerlo carácter a carácter
    // Hazlo con un bucle, te será más fácil, pero luego cambialo a hacerlo de forma
    // recursivad

#include <unistd.h>

void putstr(const char *str)
{
   int index;

    index = 0;
    while (str[index] != '\0')
    {
        write (1, &str[index], 1);
        index++;
    }

}

int main(void)
{
    putstr("Hola Sushi!!\n");
    return (0);
}

#include <unistd.h>

void putstr(const char *str)
{
    
    if (*str == '\0')
        return;
    
    write(1, str, 1);

    putstr(str + 1);
}
int main(void)
{
    putstr("Hola Sushi!!\n");
    return (0);
}*/
