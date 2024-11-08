
#include <stdlib.h>

void	*ft_memset(void	*b, int c, size_t len)
{
	size_t	index;
	char	*temp;

	temp = (char *) b;
	index = 0;
	while (index < len)
	{
		*temp = c;
		temp++;
		index++;
	}
	return (b);
}
