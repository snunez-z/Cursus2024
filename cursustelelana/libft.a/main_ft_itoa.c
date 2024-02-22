#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char *result;

	result = ft_itoa(300);
	printf("%s\n", result);
	free(result);
	result = ft_itoa(-300);
	printf("%s\n", result);
	free(result);
	result = ft_itoa(-2147483648);
	printf("%s\n", result);
	free(result);
	result = ft_itoa(2147483647);
	printf("%s\n", result);
	free(result);
	result = ft_itoa(0);
	printf("%s\n", result);
	free(result);
	return (0);	
}
