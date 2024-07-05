/*Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);*/

#include <stddef.h>

size_t	ft_strcspn (const char *s, const char *reject)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (reject [j] == s[i])
				return(i);
			j++;
		}
		i++;
	}
	return (i);	
}

#include <stdio.h>

int	main(void)
{
	int	result;

	result = ft_strcspn ("Hola", "Hola");
	printf("%d\n", result);
	result = ft_strcspn ("Hola", "ola");
	printf("%d\n", result);
	result = ft_strcspn ("Hola", "la");
	printf("%d\n", result);
	result = ft_strcspn ("Hola", "DSC");
	printf("%d\n", result);

}
