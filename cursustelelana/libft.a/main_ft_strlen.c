#include <stdio.h>
#include "libft.h"

int	main(void)
{
	size_t	len;

	len = ft_strlen("Hola mujer bonita");
	printf("%ld = %s",len, "Hola mujer bonita");
	len = ft_strlen("");
	printf("%ld",len);
	return (0);
}
