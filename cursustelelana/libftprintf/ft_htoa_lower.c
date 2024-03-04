//#include <stdio.h>
#include "libftprintf.h"
#include "libft/libft.h"

char	*ft_htoa_lower(unsigned long n)
{
	char 	*result;
	int index;

	result = ft_htoa (n);
	index = 0;
	while (result [index] != '\0')
	{
		result[index] = ft_tolower(result [index]);
		index++;
	}
	return (result);
}
/*
int	main(void)
{
	char	*result;

	result = ft_htoa_lower(255);
	printf("%s\n", result);
	free (result);
	result = ft_htoa_lower(0);
	printf("%s\n", result);
	free (result);
	result = ft_htoa_lower(15);
	printf("%s\n", result);
	free (result);
	result = ft_htoa_lower(2568945);
	printf("%s\n", result);
	free (result);
}*/
