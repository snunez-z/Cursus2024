/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:32:02 by snunez-z          #+#    #+#             */
/*   Updated: 2024/03/15 15:07:37 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 1

int	read_one_char (int fd, char *buffer)
{
	char	c;
	ssize_t read_bytes;

	read_bytes = read (fd, &c, 1);
	if (read_bytes == 1)
	{
		*buffer = c;
		return (1);
	}
	else if (read_bytes == 0)
		return (0);
	else
		return (-1);
}

int main(void)
{
	int	fd;
	char buffer [BUFFER_SIZE];
	int	result;

	fd = open ("static_var_exercises.c", O_RDONLY);
	if (fd == -1)
		return (-1);
	result = read_one_char (fd, buffer);
	if (result ==  -1)
	{
		close (fd);
		return (-1);
	}
	while ((result = read_one_char(fd, buffer)) > 0)
	{
		printf("El caracter leido es %c\n", buffer[0]);
		result++;
	}
		close (fd);
		return (0);	
}
