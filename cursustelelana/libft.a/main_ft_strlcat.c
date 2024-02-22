#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	result[20];
	size_t	len;

	ft_strlcpy (result, "Hola", 5);
	len = ft_strlcat(result, "amiga", 10);
	printf("%ld = %s\n", len, result);
	ft_strlcpy (result, "Hola", 5);
	len = ft_strlcat(result, "amiga", 2);
	printf("%ld = %s\n", len, result);
	ft_strlcpy (result, "Hola", 5);
	len = ft_strlcat(result, "amiga", 8);
	printf("%ld = %s\n", len, result);
	return (0);	
}
