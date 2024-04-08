#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	line = get_next_line (fd);
	while(line != NULL)
	{
		printf("%s", line);
		free (line);
		line = get_next_line (fd);
	}
	close (fd);
	return (0);
}
