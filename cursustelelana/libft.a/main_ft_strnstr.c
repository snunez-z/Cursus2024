#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*sub;

	sub = ft_strnstr ("Hola buena amiga","buena", 17);
	printf("%s\n", sub);
	sub = ft_strnstr ("Hola buena amiga","buena", 7);
	if (sub == 0)
		printf("ha encontrado pero no en los 7 primeros caracteres\n");
	sub = ft_strnstr ("Hola buena amiga","casa", 17);
	if (sub == 0)
		printf("No lo ha encontrado\n");
	sub = ft_strnstr ("Hola buena amiga","", 7);
	printf("%s\n", sub);
	r:WQ
	return (0);
}
