#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	*copy;

	copy = ft_substr ("HOLA SUSANA", 2, 4);
	printf("%s\n", copy);
	free(copy);
	copy = ft_substr ("HOLA SUSANA", 12, 4);
	printf("[%s]\n", copy);
	free(copy);
	copy = ft_substr ("HOLA SUSANA", 5, 8);
	printf("%s\n", copy);
	free(copy);
	return(0); 	
}
