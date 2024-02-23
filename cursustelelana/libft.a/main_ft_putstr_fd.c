
#include <unistd.h>
#include "libft.h"

int	main(void)
{
	int	stdout_fd;

	stdout_fd = 1;
	ft_putstr_fd ("Archivo 456", stdout_fd);
	write (1,"\n", 1);
	return (0);
}
