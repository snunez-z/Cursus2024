#include <stdio.h>
#include "libft.h"

int	main(void)
{
	int	*result;
	int	index;

	result = ft_calloc (1000,sizeof(int));
	if (result != 0)
		printf("Cojonudo\n");
	index = 0;
	while (index < 1000)
	{
		printf("%d ", result[index]);
		result[index] = 1;
		index++;
	}	
	free(result);
	return (0); 
}
