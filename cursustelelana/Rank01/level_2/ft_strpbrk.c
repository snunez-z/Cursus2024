/*Subject
Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2);*/

#include <stddef.h>

char	*ft_strpbrk(const char	*s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j= 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				return ((char *) &s1[i]);
			j++;
		}	
		i++;
	}
	return (NULL);
}

#include <stdio.h>

int	main(void)
{
	char	*o_found;

	o_found = ft_strpbrk ("Hola", "milasnu");
	printf("%s\n", o_found);
	return (0);
}
