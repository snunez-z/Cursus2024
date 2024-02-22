#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int value;

	value = ft_toupper('u');
	printf("%c\n", value);
	value = ft_toupper('U');
	printf("%c\n", value);
	value = ft_toupper('5');
	printf("%c\n", value);
	return (0);
}
