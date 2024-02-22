#include <stdio.h>
#include "libft.h"

int	main(void)
{
		int	c;
		int index;

		index = '0';
		while (index <= '9')
		 {
			printf("%d", ft_isdigit (index));
			index++;
		 }
		 printf("\n");
		c = ft_isdigit ('a');
		printf("%d\n", c);
		c = ft_isdigit ('B');
		printf("%d\n", c);
		c = ft_isdigit (1245);
		printf("%d\n", c);
		c = ft_isdigit ('#');
		printf("%d\n", c);
		return(0);
}
