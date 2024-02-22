#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	copy[11];
	int		n1;
	int		n2;
	char	*dst;
	char	*src;

	ft_memcpy (copy, "Hola mujer", 11);
	printf("%p %s\n", copy, copy);

	n1 = 123456;
	ft_memcpy(&n2, &n1, sizeof(int));
	printf("%d\n", n2);

	dst = &(copy[2]);
	src = &(copy[5]);
	ft_memcpy(dst, src, 4);
	printf("%s\n", copy);
}
