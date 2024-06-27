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

int main (void)
{
	printf ("El numero de vocales existentes es : %d", vocal_search ("Hola"));
	return (0);
}
