#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

void	*util_calloc(size_t size)
{
	void	*buffer;

	buffer = ft_calloc(size, 1);
	if (!buffer)
		ft_printf("Error:\nNot enough memory\n");
	return buffer;
}