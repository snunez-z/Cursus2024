#include <unistd.h>
#include "libft.h"

int main(void)
{
	int	stdout_fd;

	stdout_fd = 1;
	ft_putendl_fd ( "Hola", stdout_fd);	
	return (0);
}
