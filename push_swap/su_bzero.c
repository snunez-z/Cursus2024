#include <stdlib.h>
#include stddef.h>

void	ft_bzero(void *s, size_t n)
{
	su_memset(s, 0, n);
}
