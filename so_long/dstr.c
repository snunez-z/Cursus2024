#include <stdlib.h>
#include <unistd.h>
#include "dstr.h"

#define BUFFER_CHUNK_SIZE	100

static void copy_buffer(char *dest, char	*source, size_t len)
{
	size_t	i;

	i = 0;
	while(i < len)
	{
		dest[i] = source[i];
		i++;
	}
}

dstr_t	*dstr_create()
{
	dstr_t *dstr;

	dstr = (dstr_t *) malloc(sizeof(dstr_t));
	if (!dstr)
		return (NULL);
	dstr->buffer_size = 10;
	dstr->buffer =(char *) malloc(dstr->buffer_size * sizeof(char));
	if (!dstr->buffer)
	{
		free (dstr);
		return (NULL);
	}
	dstr->buffer_index = 0;
	return (dstr);
}

void	dstr_destroy(dstr_t *dstr)
{
	free (dstr->buffer);
	free (dstr);
}

char	dstr_char_at(dstr_t *dstr, size_t pos)
{
	return (dstr->buffer[pos]);
}

int	dstr_append_char(dstr_t *dstr, char ch)
{
	char	*new_buffer;

	if (dstr->buffer_index >= dstr->buffer_size)
	{
		new_buffer =(char *) malloc ((dstr->buffer_size + BUFFER_CHUNK_SIZE) * (sizeof(char)));
		if(!new_buffer)
		{
			dstr_destroy(dstr);
			return (0);
		}
		copy_buffer(new_buffer, dstr->buffer, dstr->buffer_size);
		free(dstr->buffer);
		dstr->buffer = new_buffer;
		dstr->buffer_size = dstr->buffer_size + BUFFER_CHUNK_SIZE;
	}
	dstr->buffer[dstr->buffer_index] = ch;
	dstr->buffer_index++;
	return (1);
}

size_t	dstr_length(dstr_t * dstr)
{
	return (dstr->buffer_index);
}

void	dstr_write(dstr_t *dstr, int fd, int new_line)
{
	if (dstr->buffer_index > 0)
		write(fd, dstr->buffer, dstr->buffer_index);
	if (new_line)
		write(fd, "\n", 1);
}

/*
int	main(void)
{
	dstr_t * dstr;
	char ch;

	dstr = create ();

	ch = 'a';
	while (ch <= 'z')
	{
		append_char(dstr, ch);
		ch++;
	}

	printf("%ld\n", lenght(dstr));

	ch = 'a';
	while (ch <= 'z')
	{
		printf("%c", char_at (dstr, ch - 'a'));
		ch++;
	}

	destroy(dstr);
	return (0);
}
*/