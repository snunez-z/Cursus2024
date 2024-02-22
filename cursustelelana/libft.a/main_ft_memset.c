#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	buffer [5];
		
	ft_strlcpy(buffer, "Hola", 5);
	ft_memset(buffer, '0', 3);
	printf("%s\n", buffer);
	ft_memset(buffer, '2', 0);
	printf("%s\n", buffer);
	return(0);
}
