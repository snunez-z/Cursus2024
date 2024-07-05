/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src);*/

#include <stdlib.h>


char	*ft_strdup(char	*src)
{
	char	*copy;
	int	i;

	i = 0;
	copy = malloc (strlen (src + 1;) * sizeof (char));
	if (copy == NULL)
	{
		free copy;
		return (NULL);
	}
	while (src[i] != '\n')
	{
		copy = src[i];
		i++;
	}
	return (copy);
}

#include <stdio.h>

int	main(void)
{
	char	*copy;
	
	copy = strdup ("Hola");
	printf("%s\n", copy)
	free (copy);
	return (0);
}
