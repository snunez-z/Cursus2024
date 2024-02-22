#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int	num;

	num = ft_atoi("300");
	printf("%d\n", num);
	num = ft_atoi("-300");
	printf("%d\n", num);
	num = ft_atoi("+300");
	printf("%d\n", num);
	num = ft_atoi("      300");
	printf("%d\n", num);
	num = ft_atoi("      300");
	printf("%d\n", num);
	return (0);
}
