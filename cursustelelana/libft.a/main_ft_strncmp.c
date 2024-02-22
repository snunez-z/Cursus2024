#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int	result;

	result = ft_strncmp("Hola", "Hola", 5);
	printf("%d\n", result);
	result = ft_strncmp("Hola", "Holas", 4);
	printf("%d\n", result);
	result = ft_strncmp ("Hola", "Holas", 5);
	printf("%d\n", result);
	result = ft_strncmp ("Holas", "Hola", 5);
	printf("%d\n", result);
}

