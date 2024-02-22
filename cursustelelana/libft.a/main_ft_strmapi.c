#include <stdio.h>
#include "libft.h"

static char	convert_to_lower(unsigned int a, char c)
{
	(void)(a);
	return (ft_tolower(c));
}

int	main(void)
{
	char	*copy;

	copy = ft_strmapi(" SUSANA NUnEZ ZAMORA", convert_to_lower);
	printf("%s\n", copy);
	free(copy);
	return (0);	
}
