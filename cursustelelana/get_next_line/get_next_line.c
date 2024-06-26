/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 07:36:02 by snunez-z          #+#    #+#             */
/*   Updated: 2024/05/17 11:21:11 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include "get_next_line.h"

#define MALLOC_SIZE 30

static int	read_one_char(int fd, char *dest)
{
	static char	buffer[BUFFER_SIZE];
	static int	buffer_size = 0;
	static int	buffer_index = 0;

	if (buffer_index >= buffer_size)
	{
		buffer_size = read(fd, buffer, BUFFER_SIZE);
		if (buffer_size == -1)
			return (-1);
		if (buffer_size == 0)
			return (0);
		buffer_index = 0;
	}
	*dest = buffer[buffer_index];
	buffer_index++;
	return (1);
}

char	*get_next_line(int fd)
{
	t_dstr	*line;
	char	ch;
	int		read_result;

	read_result = read_one_char(fd, &ch);
	if (read_result <= 0)
		return (NULL);
	line = dstr_create();
	if (line == NULL)
		return (NULL);
	while (read_result > 0)
	{
		line = dstr_append_char(line, ch);
		if (line == NULL)
			return (NULL);
		if (ch == '\n')
			return (dstr_reduce(line));
		read_result = read_one_char(fd, &ch);
	}
	if (read_result < 0)
		return (dstr_destroy(line));
	return (dstr_reduce(line));
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
		printf("usage %s <file> ...\n", argv[0]);
		return (-1);
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
}*/
