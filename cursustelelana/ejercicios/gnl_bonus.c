
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "get_next_line.h"

#define MALLOC_SIZE 10

// Esta función va a retornar el t_gnl_bonus para el fd que nos indiquen,
// porque como viste ayer, si no tenemos separados los buffer's de cada
// fd, acabamos mezclando (recuerda lo que pasó ayer en la última prueba
// que hiciste antes de irte a casa)
// Esta función recibe el fd del que queremos leer y va a retornar el t_gnl_bonus
// con el buffer, size e index específico de ese fd
// Pero vamos a ir haciéndola paso a paso
static t_gnl_bonus	*search_fd(int fd)
{
	// Define una estática de ese tipo

    // Busca en el array (campo "buffer" del struct "open_files") el elemento
    // que pertenezca al "fd" que te pasan como parámetro.
    // Si lo encuentras, devuelve el puntero a ese elemento del array
    // Si no lo encuentras, retorna NULL
}

static int	read_one_char(int fd, char *dest)
{
    // Vamos a usar una variable solo, de tipo t_gnl_bonus
	// static char	buffer[BUFFER_SIZE];
	// static int	buffer_size = 0;
	// static int	buffer_index = 0;
    t_gnl_bonus		*fd_data;

	fd_data = search_fd(fd);

	// Adapta este código para que use fd_data
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
/*#include <fcntl.h>
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
		printf("%s", line);
		free (line);
		line = get_next_line (fd);
	}
	close (fd);
	return (0);
}*/
