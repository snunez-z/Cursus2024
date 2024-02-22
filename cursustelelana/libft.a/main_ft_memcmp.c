#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int	result;

	result = ft_memcmp("Hola", "Hola", 5);
	printf("%d\n", result);
	result = ft_memcmp("Hola", "Holas", 3);
	printf("%d\n", result);
	result = ft_memcmp("Holas", "Hola", 5);
	printf("%d\n", result);
	result = ft_memcmp("Hola", "Holas", 5);
	printf("%d\n", result);
	return (0);	
}
