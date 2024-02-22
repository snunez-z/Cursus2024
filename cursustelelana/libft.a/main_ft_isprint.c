#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int	index;
	int	c;

	index = ' ';
	while (index <= '~')
	{
		printf("%d", ft_isprint(index));
		index++;
	}
	printf("\n");
	c = ft_isprint(123);
	printf("%c = %d\n", 123, c);
	c = ft_isprint(28);
	printf("%d\n", c);
	c = ft_isprint('2');
	printf("%d\n", c);
	return (0);
}
