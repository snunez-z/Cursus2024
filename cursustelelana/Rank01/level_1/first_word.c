/* subject
Write a program that takes a string and displays its first word, followed by a
newline.
Escribe un programa que reciba una cadena y retorne su primera palabra seguida de un salto de linea.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.
la palabra es una parte de la cadena separada por espacio o por el comienzo/final de la cadena.

If the number of parameters is not 1, or if there are no words, simply display
a newline.
Si el numero de parametros no es 1 o no hay palabras simplemente retorna una nueva linea.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...    is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>*/

/*
#include <unistd.h>

int	main (int argc, char **argv)
{
	int	index;

	if (argc == 2)
	{
		index = 0;
		while (argv[1][index] == ' ' || argv[1][index] == '\n')
			++index;
		while ((argv [1][index] != ' ' || argv[1][index]!= '\n') && argv[1][index])
		{
			write(1, &argv[1][index], 1);
			index++;
		}
	}
	write (1, "\n", 1);
	return (0);
}*/
