#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	ft_putchar_fd('n', fd);
}

int	main(void)
{
	int	stdout_fd;

	stdout_fd = 1;

 	ft_putnbr_fd('5', stdout_fd);
	return (0);
}
