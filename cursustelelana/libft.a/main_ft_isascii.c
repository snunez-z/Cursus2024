#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int	c;

	c = ft_isascii('&');
	printf("%d\n", c);
	c = ft_isascii('A');
	printf("%d\n", c);
	c = ft_isascii('6');
	printf("%d\n", c);
	c = ft_isascii(174);
	printf("%d\n", c);
	c = ft_isascii((int)"125");
	printf("%d\n", c);
}
