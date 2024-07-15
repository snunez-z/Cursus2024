/*Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>*/

#include <unistd.h>

int	main (int argc,	char	**argv)
{
	
	char	*str;
	int	i;
	
	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (str[i] != '\0')
			i++;
		i--;
		while (str[i] == ' ' || (str [i] >= 9 && str [i] <= 13) && i >= 0)
			i--;
		while (str[i] != ' ' && !(str [i] >= 9 && str [i] <= 13))
			i--;
		i++;
		while (str[i] != '\0' && !(str [i] >= 9 && str [i] <= 13) && str[i] != ' ')
		{
			write (1, &str[i], 1);
			i++;	
		}	
	}
	write (1, "\n", 1);
	return (0);
}
