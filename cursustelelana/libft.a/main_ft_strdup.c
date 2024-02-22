#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*copy;
	
	copy = ft_strdup("Hola amiga");
	printf("%s\n", copy);
	free(copy);
	return (0);
}
