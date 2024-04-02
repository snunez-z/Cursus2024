#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

typedef	struct dstr
{
	char	*buffer;
	size_t	buffer_size;
	size_t	str_len;
}t_dstr;

t_dstr	*dstr_create()
{
	t_dstr	*reservation;

	reservation = malloc (1 * sizeof(t_dstr));
	if (reservation == NULL)
		return (NULL);
	reservation->buffer = malloc (11 * sizeof (char));
	if (reservation->buffer == NULL)
		return (NULL);
	reservation->buffer [0]  = '\0';
	reservation->buffer_size = 10;
	reservation->str_len = 0;
	return (reservation);
}
t_dstr	*dstr_destroy(t_dstr	*reservation)
{
	free (reservation->buffer);
	free (reservation);
	return (NULL);
}
static int read_one_char(int fd, char *buffer)
{
	return read(fd, buffer, 1);
}
t_dstr  *dstr_append_char(t_dstr    *dest_dstr, char ch)
{
    char *new_buffer;

    if (dest_dstr->str_len >= dest_dstr->buffer_size)
    {
        new_buffer = malloc((dest_dstr->buffer_size + 10 + 1) * sizeof(char)); 
        copy_buffer(new_buffer, dest_dstr->buffer, dest_dstr->buffer_size + 1);
        free(dest_dstr->buffer);
        dest_dstr->buffer = new_buffer;
        dest_dstr->buffer_size = dest_dstr->buffer_size + 10;
    }

    dest_dstr->buffer[dest_dstr->str_len] = ch;
    dest_dstr->buffer[dest_dstr->str_len + 1] = '\0';
    dest_dstr->str_len++;

    return (dest_dstr);
}
void copy_buffer(char *dest, char *source, size_t len)
{
    size_t index;

    index = 0;
    while(index < len)
    {
        dest[index] = source[index];
        index++;
    }
}
char	*get_next_line(int	fd)
{
	char	ch;
	int		read_result;
	t_dstr	*reservation;
	int		index;

	read_result = read_one_char(fd, &ch);
	if (read_result <= 0)
		return((void *)NULL);
	dstr_append_char (reservation, ch);
	reservation->buffer = dstr_create ();
	
	index = 1;
	while(ch != '\n')
	{
		read_result = read_one_char(fd, &ch);
		if (read_result < 0)
			return (dstr_destroy(reservation->buffer));
		else if (read_result == 0)
        {
            reservation->buffer[index] = '\0';
            return (reservation->buffer);
        }
		reservation->buffer[index] = ch;
		index++;
	}
	reservation->buffer[index] = '\0';
	return (reservation->buffer);
}
#include <stdio.h>
int main(int	argc, char **argv)
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
	printf("[%s]\n", line);free(line);
	close(fd);
	return (0);
}