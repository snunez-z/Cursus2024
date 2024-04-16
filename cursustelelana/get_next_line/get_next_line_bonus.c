/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:23:24 by snunez-z          #+#    #+#             */
/*   Updated: 2024/04/15 19:19:32 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "get_next_line_bonus.h"

#define MALLOC_SIZE 30

static t_gnl_bonus	*search_fd(int fd)
{
	static t_open_files	fd_to_open = {
		.fd_num = 0
	};
	size_t				index;
	t_gnl_bonus			*one_file_data;

	index = 0;
	while (index < fd_to_open.fd_num)
	{
		one_file_data = &(fd_to_open.buffer[index]);
		if (one_file_data->fd == fd)
			return (one_file_data);
		index++;
	}
	index = fd_to_open.fd_num;
	one_file_data = &(fd_to_open.buffer[index]);
	one_file_data->buffer_size = 0;
	one_file_data->buffer_index = 0;
	one_file_data->fd = fd;
	fd_to_open.fd_num++;
	return (one_file_data);
}

static int	read_one_char(int fd, char *dest)
{
	t_gnl_bonus		*fd_data;

	fd_data = search_fd(fd);
	if (fd_data->buffer_index >= fd_data->buffer_size)
	{
		fd_data->buffer_size = read(fd, fd_data->buffer, BUFFER_SIZE);
		if (fd_data->buffer_size == -1)
			return (-1);
		if (fd_data->buffer_size == 0)
			return (0);
		fd_data->buffer_index = 0;
	}
	*dest = fd_data->buffer[fd_data->buffer_index];
	fd_data->buffer_index++;
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
int	main (int argc, char **argv)
{
	char	*line;
	int	index;
	int fd_num[1024];
	int at_least_one_file_reads;

	if (argc < 2)
	{
		printf("usage:%s <file> ...\n", argv [0]);
		return (-1);
	}	
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
}*/
