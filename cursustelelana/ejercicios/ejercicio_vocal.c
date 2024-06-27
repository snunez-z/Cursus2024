
/* Este programa recibe una string y retorna el numero de vocales que tiene */

#include <stdio.h>

int	vocal_search(char	*str)
{
	char	vocals[] = "aeiou";
	int		num_vocals;
	int		i;
	
    num_vocals =0;
	while (*str != '\0')
	{
		i = 0;
		while (i < 5)
		{
			if (*str == vocals [i])
				num_vocals++;
			i++; 
		}
		str++;
	}
	return (num_vocals);
}

int main (int argc, char**argv)
{
	int num_vocales;
	num_vocales = vocal_search (argv[1]);
	printf ("El numero de vocales existentes es : %d\n", num_vocales);
	return (0);
}
