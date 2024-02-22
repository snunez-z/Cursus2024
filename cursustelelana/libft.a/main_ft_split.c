#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char	**split;
	int		index;

	split =ft_split ("    SUSANA NUÑEZ   ZAMORA", ' ');
	index = 0;
	while (split[index] != 0)
	{	
		printf("%s\n", split[index]);
		free(split);
		index++;
	}
	free(split);
	return (0);
}
