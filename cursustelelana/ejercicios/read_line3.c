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
	int		read_result;
	char	*buffer;

	// Esta es una posible solución al ejercicio anterior
	// En este ejercicio, tienes que ponerle protecciones:
	// Si malloc falla, tienes que retornar NULL
	// Si alguna lectura falla o no lee nada, tienes que liberar el malloc y retornar NULL
	buffer = malloc(1000 * sizeof(char));
	index = 0;
	while(index < 10)
	{
		read_one_char(fd, &ch);
		buffer[index] = ch;
		index++;
	}

	buffer[index] = '\0';
	return buffer;
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
