
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_bytes;
	void	*result;

	total_bytes = count * size;
	result = malloc(total_bytes);
	if (result)
		su_bzero(result, total_bytes);
	return (result);
}
