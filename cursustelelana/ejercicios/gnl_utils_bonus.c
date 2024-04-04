
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

#define MALLOC_SIZE 10

static void	copy_buffer(char *dest, char *source, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		dest[index] = source[index];
		index++;
	}
}

t_dstr	*dstr_create(void)
{
	t_dstr	*pdstr;

	pdstr = malloc(1 * sizeof(t_dstr));
	if (pdstr == NULL)
		return (NULL);
	pdstr->buffer = malloc((MALLOC_SIZE + 1) * sizeof(char));
	if (pdstr->buffer == NULL)
	{
		free(pdstr);
		return (NULL);
	}
	pdstr->buffer[0] = '\0';
	pdstr->buffer_size = MALLOC_SIZE;
	pdstr->str_len = 0;
	return (pdstr);
}

char	*dstr_destroy(t_dstr *pdstr)
{
	free(pdstr->buffer);
	free(pdstr);
	return (NULL);
}

char	*dstr_reduce(t_dstr	*pdstr)
{
	char	*reduced_buffer;

	if (pdstr->str_len == pdstr->buffer_size)
	{
		reduced_buffer = pdstr->buffer;
		free(pdstr);
		return (reduced_buffer);
	}
	reduced_buffer = malloc((pdstr->str_len + 1) * sizeof(char));
	if (reduced_buffer == NULL)
	{
		dstr_destroy(pdstr);
		return (NULL);
	}
	copy_buffer(reduced_buffer, pdstr->buffer, pdstr->str_len + 1);
	dstr_destroy(pdstr);
	return (reduced_buffer);
}

t_dstr	*dstr_append_char(t_dstr *dest_dstr, char ch)
{
	char	*new_buffer;

	if (dest_dstr->str_len >= dest_dstr->buffer_size)
	{
		new_buffer = malloc((dest_dstr->buffer_size + MALLOC_SIZE + 1)
				* sizeof(char));
		if (new_buffer == NULL)
		{
			dstr_destroy(dest_dstr);
			return (NULL);
		}
		copy_buffer(new_buffer, dest_dstr->buffer, dest_dstr->buffer_size + 1);
		free(dest_dstr->buffer);
		dest_dstr->buffer = new_buffer;
		dest_dstr->buffer_size = dest_dstr->buffer_size + MALLOC_SIZE;
	}
	dest_dstr->buffer[dest_dstr->str_len] = ch;
	dest_dstr->buffer[dest_dstr->str_len + 1] = '\0';
	dest_dstr->str_len++;
	return (dest_dstr);
}


