#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*len;
	len = ft_itoa(n);
	ft_putstr_fd(len, fd);
	free(len);
}

int	main(void)
{
	int	stdout_fd;

	stdout_fd = 1;

 	ft_putnbr_fd(555, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(-555, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(-1247000, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(0, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(35, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(2147483647, stdout_fd);
	printf("\n");
 	ft_putnbr_fd(-2147483648, stdout_fd);
	printf("\n");
	return (0);
}
