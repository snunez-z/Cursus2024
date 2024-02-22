#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*result;

	result = ft_memchr("SONORO",'O', 3);
	printf("%s\n", result);
	result = ft_memchr("SONORO",'a', 4);
	if (result == 0)
		printf("No lo ha encontrado\n");
	result = ft_memchr("SONORO",'O' + 256, 3);
	printf("%s\n", result);
	return (0);	
}
