#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "get_next_line.h"

#define MALLOC_SIZE 10

static char	*free_buffer(char	*buffer)
{
	free(buffer);
	return (NULL);
}

char	*terminate_and_reduce(char	*buffer, size_t used_chars,
			size_t buffer_size)
{
	buffer[used_chars + 1] = '\0';
	if(used_chars < buffer_size)
		buffer = ft_reduce(buffer, used_chars + 2);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	size_t	current_size;
	size_t	used_chars;
	int		bytes_read;
	char	ch;

	if((buffer = malloc ((MALLOC_SIZE + 1) * sizeof (char))) == NULL)
		return (NULL);
	if ((bytes_read = read_one_char(fd, buffer)) <= 0)
		return free_buffer(buffer);
	current_size = MALLOC_SIZE;
	used_chars = 0;
	while (bytes_read > 0 && buffer[used_chars] != '\n')
	{
		if ((bytes_read = read_one_char (fd, &ch)) == -1)
			return free_buffer(buffer);
		if (bytes_read > 0)
		{
			if ((++used_chars) >= current_size)
				if ((buffer = ft_realloc(buffer, &current_size))  == NULL)
					return (NULL);
			buffer[used_chars] = ch;
		}
	}
	return (terminate_and_reduce(buffer, used_chars, current_size));
}
/*

#include <fcntl.h>
#include <stdio.h>
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
		printf("[%s]\n", line);
		free (line);
		line = get_next_line (fd);
	}
	close (fd);
	return (0);
} */
