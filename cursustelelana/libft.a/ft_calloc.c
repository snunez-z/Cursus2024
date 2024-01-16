#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

void	* ft_calloc(size_t quantity, size_t size_of_each_element)
{
	size_t total_bytes = quantity * size_of_each_element;
	void *result = malloc(total_bytes);
	ft_bzero(result, total_bytes);
	return result;
}

int	main(void)
{	
	int *numbers;
	numbers = ft_calloc (100, sizeof (int));
	int index = 0;
	while(index < 100)
	{
		printf("%d", numbers[index]);
		index++;
	}
	return (0);
}
