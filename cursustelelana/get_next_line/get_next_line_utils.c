#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stddef.h>

#define MALLOC_SIZE 10

char	*ft_reduce(char *buffer, size_t buffer_size)
{
	char	*result;
	size_t	index;

	result = malloc(buffer_size * sizeof(char));
	if (result == NULL)
	{
		free (buffer);
		return (NULL);
	}
	index = 0;
	while (index < buffer_size)
	{
		result[index] = buffer[index];
		index++;
	}
	free(buffer);
	return (result);
}

char	*ft_realloc(char *old_buffer, size_t *buffer_size)
{
	char	*result;
	size_t  new_buffer_size;
	size_t	index;

	new_buffer_size = *buffer_size + MALLOC_SIZE; 
	result = malloc((new_buffer_size + 1) * sizeof(char));
	if (result == NULL)
	{
		free (old_buffer);
		return (NULL);
	}
	index = 0;
	while (index < *buffer_size)
	{
		result[index] = old_buffer[index];
		index++;
	}
	free(old_buffer);
	*buffer_size = new_buffer_size;
	return (result);
}

int	read_one_char(int fd, char *buffer)
{
	static char		persistent_buffer[BUFFER_SIZE];
	static int		bytes_stored = 0;
	static ssize_t	bytes_read = 0;

	if (bytes_stored >= bytes_read)
	{
		bytes_read = read (fd, persistent_buffer, BUFFER_SIZE);
		bytes_stored = 0;
		if (bytes_read == 0)
			return (0);
		else if (bytes_read == -1)
			return (-1);
	}
	*buffer = persistent_buffer[bytes_stored];
	bytes_stored++;
	return (1);
}
