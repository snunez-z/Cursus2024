#include <stdio.h>

void	*ft_memchr(const void *s, int	c, size_t n)
{
	size_t index;
	char *aux;
		
	aux = (char*)s;
	index = 0;
	while (index < n)
	{
		if (*aux == c)
		{
			return (aux);
		}
		else
		{
			aux++;
		}
	index ++;
	}
	return (0);
}

int	main(void)
{
	char	*str;

	str = ft_memchr("Hola", 'l', 4);
	printf("%s\n", str);
	str = ft_memchr("Hola", 'l', 2);
	if (str == 0)
	{
		printf("No lo ha encotrado\n");
	}
	return (0);
}

