#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*result;

	result = ft_strchr ("HOLA AMIGA", 'L');
	printf("%s\n", result);
	result = ft_strchr ("HOLA AMIGA", 'L' + 256);
	printf("%s\n", result);
	result = ft_strchr ("HOLA AMIGA", 'n');
	if (result == 0)
		printf(" No lo encuentra");
	return (0);
}
