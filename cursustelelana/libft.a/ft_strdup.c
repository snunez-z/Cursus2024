#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char* src)
{
	unsigned int size = ft_strlen(src) + 1;
	char *copy = malloc(size * sizeof(char));
	ft_strlcpy(copy, src, size);
	return (copy);
}
int	main(void)
{
	char	*copy;

	copy = ft_strdup("Hola");
	printf("%s\n", copy);
	free(copy);
	return (0);
}
