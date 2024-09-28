#include <stdlib.h>
#include "dstr.h"
#include <stdio.h>
t_dstr	*create()
{
	t_dstr *dstr;

	dstr = (t_dstr *) malloc(sizeof(t_dstr));
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

void	destroy(t_dstr *dstr)
{
	free (dstr->buffer);
	free (dstr);
}

char	char_at(t_dstr *dstr, size_t pos)
{
	return (dstr->buffer[pos]);
}

void copy_buffer(char *dest, char	*source, size_t len)
{
	size_t	i;

	i = 0;
	while(i < len)
	{
		dest[i] = source[i];
		i++;
	}
}

int	append_char (t_dstr *dstr, char ch)
{
	char	*new_buffer;

	if (dstr->buffer_index >= dstr->buffer_size)
	{
		new_buffer =(char *) malloc ((dstr->buffer_size + 10) * (sizeof(char)));
		if(!new_buffer)
		{
			destroy(dstr);
			return (0);
		}
		copy_buffer(new_buffer, dstr->buffer, dstr->buffer_size);
		free(dstr->buffer);
		dstr->buffer = new_buffer;
		dstr->buffer_size = dstr->buffer_size + 10;
	}
	dstr->buffer[dstr->buffer_index] = ch;
	dstr->buffer_index++;
	return (1);
}
size_t	lenght (t_dstr * dstr)
{
	return (dstr->buffer_index);
}

int	main(void)
{
	t_dstr * dstr;
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

