#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	buffer[5];

	ft_strlcpy(buffer, "Hola", 5);
	ft_bzero(buffer, 2);
	printf("%s\n", buffer);
	printf("%s\n", buffer + 1);
	printf("%s\n", buffer + 2);
	return (0);
}
