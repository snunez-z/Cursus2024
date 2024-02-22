#include <stdio.h>
#include "libft.h"

int main(void)
{
		int	c;

		c = ft_isalpha ('d');
		printf("%d\n", c);
		c = ft_isalpha ('D');
		printf("%d\n", c);
		c = ft_isalpha ('3');
		printf("%d\n", c);
		c = ft_isalpha ('&');
		printf("%d\n", c);
		return (0);
}
