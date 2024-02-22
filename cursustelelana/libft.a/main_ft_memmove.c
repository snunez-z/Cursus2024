#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	copy [50];
	int		n1;
	int	 	n2;
	char	*src;
	char	*dst;

	ft_memmove(copy,"Hola Muchachita",5);
	copy[5] = '\0';
	printf("%s\n",copy);

	n1 = 1235;
	ft_memmove(&n2, &n1,sizeof(int));
	printf("%d\n", n2);
	
	src = &(copy [2]);
	dst = &(copy [4]);
	printf("copy %p, dst %p, src %p\n", copy, dst, src);
	ft_memcpy(copy,"MI CASA BONITA", 15);
	ft_memmove(dst,src,7);
	printf("%s\n",copy);
	
	src = &(copy[5]);
	dst = &(copy[2]);
	ft_memcpy(copy, "MI CASA BONITA", 15);
	ft_memmove(dst, src,6);
	printf("%s\n", copy); 
	return (0);
}
