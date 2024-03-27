/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 07:36:02 by snunez-z          #+#    #+#             */
/*   Updated: 2024/03/20 11:45:42 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "gnl.h"

#define MALLOC_SIZE 10

#include <stdio.h>
static	int	read_one_char(int fd, char *dest)
{
	static char buffer[BUFFER_SIZE];
	static int	eof = 0;
	static int	buffer_size = 0;
	static int	buffer_index = 0;

	if (eof)
		return (0);
	if (buffer_index >= buffer_size)
	{
		buffer_size = read(fd, buffer, BUFFER_SIZE);
		eof = (buffer_size <= 0);
		if (eof)
			return (buffer_size);
		buffer_index = 0;
	}

	*dest = buffer[buffer_index];
	buffer_index++;
	return 1;
}

char	*get_next_line(int fd)
{
	dstr_t	*line;
	char	ch;
	int		read_result;

	read_result = read_one_char(fd, &ch);
	if (read_result <= 0)
		return (NULL);

	line = dstr_create();
	while (line != NULL && read_result > 0)
	{
		line = dstr_append_char(line, ch);
		if (ch == '\n')
			return (dstr_reduce(line));
		read_result = read_one_char(fd, &ch);
	}

	if (line == NULL)
		return NULL;

	if (read_result < 0)
		return (dstr_destroy(line));

	return (dstr_reduce(line));
}

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
} 
