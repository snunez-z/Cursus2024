#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int read_one_char(int fd, char *buffer)
{
	return read(fd, buffer, 1);
}

static char	*get_next_line(int fd)
{
	typedef	struct	dstr
	{
		char	*buffer;
		size_t	buffer_size;
		size_t	str_len;
	} t_dstr;

	char	ch;
	int		index;
	int		read_result;

	// Esta es una posible solución al ejercicio anterior
	// En este ejercicio, tienes que modificarlo para usar dstr_t
	// El hecho de usar dstr_t te va a permitir optimizar la memoria
	// porque no reservas 1000 caracteres (en el 99% de los casos te
	// va a sobrar) y además ir creciendo el buffer conforme te vaya
	// haciendo falta
	read_result = read_one_char(fd, &ch);
	if (read_result <= 0)
		return (NULL);
	t_dstr->buffer_size = 10;
	t_dstr->buffer = malloc(t_dstr->buffer_size + 1 * sizeof(char));
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
int main()
{
	int		fd;
	char	*line;

	if (argc < 2)
	{
		printf("Error: You have to indicate the file to read from\n");
		return (-1);
	}

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	printf("[%s]\n", line);
	free(line);
	close(fd);
	return (0);
}
