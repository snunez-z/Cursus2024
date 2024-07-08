/*Assignment naeare	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
----------------------------0-----------------------------------

Reproduce exactly the behavior of the strn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept);*/

#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;
	int	ocurrence;
	
	i = 0;
	while (s[i] != '\0')
	{
		
		ocurrence = 0;
		j = 0;
		while (accept[j] !='\0')
		{
			if (s[i] == accept [j])
				ocurrence = 1;
			j++;
		}
		if (ocurrence == 0)
			return (i);
		i++;
	}
	return (i);
}

#include <stdio.h>

int	main (void)
{
	size_t	num_ocurrences;

	num_ocurrences = ft_strspn ("ola", "olas");
	printf ("%ld\n", num_ocurrences);
	return (0);
}
