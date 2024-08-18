
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "get_next_line_bonus.h"

#include <fcntl.h>
#include <stdio.h>
/*int	main(int argc, char **argv)
{
	int	fd;
	int	fd2;
	char	*line;
	char	*line2;

	if (argc < 2)
	{
		printf("Error\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	fd2 = open(argv[2], O_RDONLY);
	line2 = get_next_line (fd2);
	
	while(line != NULL)
	{
		printf("%s:[%s]\n", argv [1], line);
		free (line);
		printf("%s:[%s]\n", argv[2], line2);
		line = get_next_line (fd);
		line2 = get_next_line (fd2);
	}
	close (fd);
	close (fd2);
	return (0);
}*/

int	main (int argc, char **argv)
{
	char	*line;
	int	index;
	int fd_num[1024];
	int at_least_one_file_reads;
	
	index = 1;
	while (index < argc)
    {
		fd_num [index -1] = open (argv[index], O_RDONLY);
		if (fd_num [index - 1] == -1)
			return (-1);
		index ++;
	}	
		
	at_least_one_file_reads = 1;
	while (at_least_one_file_reads)
	{
		at_least_one_file_reads = 0;
		index = 0;
		while(index < (argc-1))
		{
			line = get_next_line (fd_num[index]);
			if (line != 0)
				at_least_one_file_reads = 1;
			printf("%s: %s\n", argv[index+1], line);
			free (line);
	
	        index++;
		}
	}
	index = 0;
	while(index < (argc-1))
	{
		close(fd_num[index]);
		index++;
	}
}
