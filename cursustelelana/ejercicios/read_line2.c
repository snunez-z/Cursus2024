#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int read_one_char(int fd, char *buffer)
{
	return read(fd, buffer, 1);
}

static char	*get_next_line(int fd)
{
	char	ch;
	int		index;
	char	*buffer;

	// Usa "malloc" para reservar espacio para 1000 caracteres
	// Usa read_one_char para leer 10 caracteres
	// RECUERDA: read_one_char lee sólo un carácter, así es que si
	//           quieres leer 10, necesitarás un bucle.
	// Al final, retorna "buffer"
}

#include <stdio.h>
int main()
{
	int		fd;
	char	*line;

	fd = open("el_principito.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("[%s]\n", line);
    free(line);
	close(fd);
	return (0);
}
