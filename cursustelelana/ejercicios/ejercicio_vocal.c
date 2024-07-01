
/* Este programa recibe una string y retorna el numero de vocales que tiene */

static int is_vowel(char ch)
{
	char vowels [] = "aeiouAEIOU";
	int	index;

	index = 0;
	while (index < 10)
	{
		if (ch == vowels [index])
			return (1);
		else 
			index++;
	}   
	return (0);
}

#include <stdio.h>

int main (int argc, char**argv)
{
	
	if (argc < 2)
		return (-1);

	char	*str;
	int		num_vocals;
	int		index;

	str = argv [1];
	while (*str != '\0')
	{
		num_vocals = 0;
		if (is_vowel(*str))
			num_vocals++;
		str++;
	}
	printf ("%d\n", num_vocals);
	return (0);
}

