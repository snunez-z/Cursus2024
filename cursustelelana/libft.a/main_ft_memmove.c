#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	buffer [50];
	int		n1;
	int		n2;
	char	*src;
	char	*dst;

	ft_memmove(buffer, "Hola", 5);
	printf("%s\n", buffer);

	n1 = 1235;
	ft_memcpy(&n2, &n1, sizeof(int));
	printf("%d\n", n2);

	src = &(buffer[2]);
	dst = &(buffer[0]);
	ft_memcpy (buffer, "Hola muchachita", 16);
	ft_memmove (dst, src, 4);
	printf("%s\n",buffer);

	src = &(buffer[0]);
	dst = &(buffer[2]);  
	ft_memcpy(buffer, "Hola muchachita", 16);
	ft_memmove(dst, src, 4);
	printf("%s\n", buffer);
	printf("%s\n", dst);
	return (0);
}
