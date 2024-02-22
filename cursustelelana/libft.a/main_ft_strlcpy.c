#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	copy[100];
	size_t	len;

	len = ft_strlcpy(copy,"Hola amiga", 10);
	printf("%ld = %s\n", len, copy);
	len = ft_strlcpy(copy, "",2);
	printf("%ld\n", len);
	len = ft_strlcpy(copy, "HOla amiga", 0);
	printf("%ld\n", len);
	return (0);
}
