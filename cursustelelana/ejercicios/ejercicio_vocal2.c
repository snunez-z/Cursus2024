//Este programa recibe una string y retorna el numero de vocales que tiene 
// si no recibe ningun parametro tiene que sacar 0

int	is_vowel (char ch)
{
	char	vowels []= "aeiouAEIOU";
	int	index;

	index = 0;
	while (index < 10)
	{
		if(ch == vowels[index])
			return (1);
		else
			index++;
	}
	return (0);
}

#include <stdio.h>

int main (int	argc, char** argv)
{
	int		num_vocals;
	char	*str;

	if (argc == 1)
	{
		printf ("0\n");
		return (-1);
	}
	num_vocals = 0;
	str = argv [1];
	while (*str != '\0')
	{
		if (is_vowel (*str))
			num_vocals++;
		str++;
	}
	printf (" Num of vocals is = %d\n", num_vocals);
	return (0);
}
