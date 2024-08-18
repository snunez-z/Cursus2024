#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>

static char *ft_realloc(char *old_buffer, size_t old_buffer_size, size_t new_buffer_size)
{
	char *result;
	size_t index;

	// 1. Malloc del nuevo
	result = malloc(new_buffer_size * sizeof(char));
	if (result == NULL)
		return (NULL);

	// 2. Si no falla, copiar del old al new
	index = 0;
	while(index < old_buffer_size)
	{
		result[index] = old_buffer[index];
		index++;
	}
	// 3. Liberar viejo
	free(old_buffer);
	// 4. Retornar el nuevo
	return result;
}

int	read_one_char(int fd, char *buffer)
{
	static int cuantos_reads = 0;
	/*
	char c;
	ssize_t bytes_read;

	bytes_read = read (fd, &c, 1);
	cuantos_reads++;
	printf("Llevo %d reads\n", cuantos_reads);
	if (bytes_read == 0)
		return (0);
	else if (bytes_read == -1)
		return (-1);
	*buffer = c;
	return (1);
	*/
	static char persistent_buffer[BUFFER_SIZE];
	static int bytes_stored = 0;
	static ssize_t bytes_read = 0;
	
	if (bytes_stored >= bytes_read)
	{
		bytes_read = read (fd, persistent_buffer, BUFFER_SIZE);
		bytes_stored = 0;
		cuantos_reads++;
		printf("Llevo %d reads\n", cuantos_reads);
		if (bytes_read == 0)
			return (0);
		else if (bytes_read == -1)
			return (-1);
	}
	printf("bytes_read %ld bytes_stored %d\n", bytes_read, bytes_stored);
	*buffer = persistent_buffer[bytes_stored];
	bytes_stored++;
	return (1);
}

char *get_next_line(int fd)
{
	/*
	char	*buffer;
	char	*line;
	int	bytes_read;

	buffer = malloc (1000 * sizeof (char));
	if (buffer == 0)
		return (NULL);
	line = buffer;
	bytes_read = read_one_char(fd, buffer);
	if (bytes_read == 0 || bytes_read == -1)
	{
		free (buffer);
		return (NULL);
	}
	while (bytes_read > 0 && *buffer != '\n')
	{
		buffer++;
		bytes_read = read_one_char (fd, buffer);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
	}
	*(buffer + 1) = '\0';
	return (line);
	*/
	char   *buffer;
	size_t current_size;
	size_t used_chars;
	int    bytes_read;

	// 1. Reservar el buffer inicial
	buffer = malloc (10 * sizeof (char));
	if (buffer == 0)
		return (NULL);
	current_size = 10;

	// 2. Si va bien, empezar a leer caracter a caracter hasta bla bla bla
	used_chars = 0;
	bytes_read = read_one_char(fd, buffer);
	if (bytes_read == 0 || bytes_read == -1)
	{
		free (buffer);
		return (NULL);
	}
	while (bytes_read > 0 && buffer[used_chars] != '\n')
	{
		used_chars++;
		if (used_chars >= current_size)
		{
			printf("Voy a agrandar de %ld hasta %ld\n", current_size, current_size + 10);
			buffer = ft_realloc(buffer, current_size, current_size + 10);
			current_size = current_size + 10;
		}
		bytes_read = read_one_char (fd, buffer + used_chars);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
	}
	buffer[used_chars + 1] = '\0';
	return (buffer);
}

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("texto.txt", O_RDONLY);
	line = get_next_line (fd);
	while(line != NULL)
	{
		printf("[%s]\n", line);
		free (line);
		line = get_next_line (fd);
	}
	close (fd);
	return (0);
}
