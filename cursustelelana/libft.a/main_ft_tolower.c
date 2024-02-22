#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int	value;

	value = ft_tolower('U');
	printf("%c\n", value);
	value = ft_tolower('5');
	printf("%c\n", value);
	value = ft_tolower(5);
	printf("%c\n", value);
	return (0);
}
