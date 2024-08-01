/*Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);*/

#include <string.h>

char	*ft_strrev(char	*str)
{
	int	len;
	char	aux;
	int	i;

	i = 0;
	len = 0;

        while (str[len] != '\0')
		len++;
	len = len -1;
	while (i < len)
	{	
		aux = str[i];
		str[i] = str[len];
		str[len] = aux;
		i++;	
		len--;
	}
	return (str);
}

#include <stdio.h>

int	main (void)
{
	char	message [] = " HOLA AMIGA DEL ALMA";
	
	printf( "%s\n", ft_strrev (message));
	return (0);
}
