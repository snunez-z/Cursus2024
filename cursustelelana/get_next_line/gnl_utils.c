#include <stdio.h>
#include <stdlib.h>
#include "gnl.h"

static void copy_buffer(char *dest, char *source, size_t len)
{
	size_t index;

	index = 0;
	while(index < len)
	{
		dest[index] = source[index];
		index++;
	}
}

dstr_t	*dstr_create()
{
	dstr_t  *pdstr;

	pdstr = malloc(1 * sizeof(dstr_t));
	pdstr->buffer = malloc(11 * sizeof(char));
	pdstr->buffer[0] = '\0';
	pdstr->buffer_size = 10;
	pdstr->str_len = 0;
	return (pdstr);
}

char	*dstr_destroy(dstr_t *pdstr)
{
	free(pdstr->buffer);
	free(pdstr);
	return (NULL);
}

char	*dstr_reduce(dstr_t	*pdstr)
{
	char	*reduced_buffer;
	if (pdstr->str_len == pdstr->buffer_size)
	{
		reduced_buffer = pdstr->buffer;
		free(pdstr);
		return reduced_buffer;
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

dstr_t	*dstr_append_char(dstr_t    *dest_dstr, char ch)
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

