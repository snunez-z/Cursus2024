#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*result;

	result = ft_strrchr( "HOLA AMIGA", 'A');
	printf("%s\n", result);
	result = ft_strrchr ("HOLA AMIGA", 'A' + 256);
	printf("%s\n", result);

	result = ft_strrchr(" HOLA AMIGA", 'S');
	if (result == 0)
		printf("No lo encuentra");
	return (0);
}
