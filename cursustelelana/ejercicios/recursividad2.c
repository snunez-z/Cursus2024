/*void putstr_reverse(const char *str)
{
    // Haz esta función. Lo que tiene que hacer es escribir (write) por pantalla (1)
    // la cadena de caracteres "str" pero al revés; es decir, si te pasan "Hola",
    // tiene que escribir "aloH"
    // Hazlo con recursividad
    // PISTA: La solución es como el anterior... pero cambiando el orden de una cosa
}*/

#include <unistd.h>
//#include <string.h>
/*
void putstr_reverse(const char *str)
{
	int index;

	index = strlen (str);
	while (index > 0)
	{
		index--;
		write(1 ,&str[index], 1);
	}
	write (1, "\n", 1);
}*/
void	putstr_reverse (const char *str)
{
	if (*str == '\n')
		return;
	putstr_reverse (str + 1);
	write (1, str, 1);
}

int main(void)
{
    putstr_reverse("!!ihsuS aloH\n");
    return (0);
}
