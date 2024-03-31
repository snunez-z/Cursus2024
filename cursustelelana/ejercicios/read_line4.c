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
	// En este ejercicio, tienes que modificarlo para:
	// Si no lee nada (es decir, la primera lectura falla o no lee nada)
	// tiene que retornar NULL
	// Pero si la primera lectura funciona, para las siguientes hay que
	// distinguir entre si falla o no lee nada, porque es diferente no
	// leer nada de nada que leer un carácter y luego que no haya nada.
	// En el primer caso no hay nada (y retornaremos NULL) y en el segundo
	// sí hay algo y retornaremos lo que haya leído hasta entonces
	// RECUERDA: Todo eso se refiere a si read_one_char retorna cero (no
	//           ha fallado, pero no había nada que leer). Si read_one_char
	//           retorna -1, siempre tenemos que retornar NULL (porque que
	//           read_one_char retorne -1 significa que ha habido un error)
	buffer = malloc(1000 * sizeof(char));
	if (buffer == NULL)
		return (NULL);

	index = 0;
	while(index < 10)
	{
		read_result = read_one_char(fd, &ch);
		if (read_result <= 0)
		{
			free(buffer);
			return (NULL);
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

	fd = open("el_principito.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("[%s]\n", line);
    free(line);
	close(fd);
	return (0);
}
