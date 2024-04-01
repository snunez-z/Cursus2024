#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

static int read_one_char(int fd, char *buffer)
{
	return read(fd, buffer, 1);
}

static char	*get_next_line(int fd)
{
	char	*buffer;
	char	ch;
	int	index;

	buffer = malloc (1000 * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	index = 0;
	while(index < 10)
	{
		read_one_char(fd, &ch);
		buffer[index] = ch;
		index++;
	}
	buffer[index] = '\0';
	return (buffer);
}
	// Usa "malloc" para reservar espacio para 1000 caracteres
	// Usa read_one_char para leer 10 caracteres
	// RECUERDA: read_one_char lee sólo un carácter, así es que si
	//           quieres leer 10, necesitarás un bucle.
	// Al final, retorna "buffer"

#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open ("el_principito.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	printf("[%s]\n", line);
	free (line);
	close (fd);
	return (0);
}
