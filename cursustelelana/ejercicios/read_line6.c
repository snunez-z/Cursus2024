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
	// En este ejercicio, el cambio está en el main, así es que lee
	// más abajo
	read_result = read_one_char(fd, &ch);
	if (read_result <= 0)
		return (NULL);

	buffer = malloc(1000 * sizeof(char));
	if (buffer == NULL)
		return (NULL);
    buffer[0] = ch;

	index = 1;
	while(ch != '\n')
	{
		read_result = read_one_char(fd, &ch);
		if (read_result < 0)
		{
			free(buffer);
			return (NULL);
		}
        else if (read_result == 0)
        {
            buffer[index] = '\0';
            return (buffer);
        }
		buffer[index] = ch;
		index++;
	}

	buffer[index] = '\0';
	return (buffer);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	// Cambia el main para que el nombre del fichero que se abre, lo coja de los
	// parámetros del programa (o sea, de argv)
	// Si no pasan el nombre del fichero, debes mostrar un mensaje de error y salir
	fd = open("el_principito.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("[%s]\n", line);
    free(line);
	close(fd);
	return (0);
}
