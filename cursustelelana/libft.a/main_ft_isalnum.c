#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int	c;
	int	index;
		
	c = ft_isalnum('a');
	printf("%d\n",c);
	c = ft_isalnum('A');
	printf("%d\n",c);
	c = ft_isalnum(123);
	printf("%d\n",c);
	c = ft_isalnum('&');
	printf("%d\n",c);
		
	index = '0';
	while(index <= '9')
	{
		printf("%d\n", ft_isalnum(index));
		index++;
	}
	index = 'a';
	while (index <= 'z')
	{
		printf("%d\n", ft_isalnum(index));
		index++;
	}
	index = 'A';
	while (index <= 'Z')
	{
		printf("%d\n", ft_isalnum(index));
		index++; 
	}
	return (0);
}
