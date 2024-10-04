/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:20:13 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 10:58:01 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "dstr.h"
#include "util.h"

#define BUFFER_CHUNK_SIZE	100

t_dstr	*dstr_create(void)
{
	t_dstr	*dstr;

	dstr = (t_dstr *) util_calloc(sizeof(t_dstr));
	if (!dstr)
		return (NULL);
	dstr->buffer_size = 10;
	dstr->buffer = (char *) util_calloc(dstr->buffer_size * sizeof(char));
	if (!dstr->buffer)
	{
		free (dstr);
		return (NULL);
	}
	dstr->buffer_index = 0;
	return (dstr);
}

void	dstr_destroy(t_dstr *dstr)
{
	free (dstr->buffer);
	free (dstr);
}

char	dstr_char_at(t_dstr *dstr, size_t pos)
{
	return (dstr->buffer[pos]);
}

char	dstr_set_char_at(t_dstr *dstr, size_t pos, char ch)
{
	char	previous;

	previous = dstr->buffer[pos];
	dstr->buffer[pos] = ch;
	return (previous);
}

int	dstr_append_char(t_dstr *dstr, char ch)
{
	char	*new_buffer;

	if (dstr->buffer_index >= dstr->buffer_size)
	{
		new_buffer = (char *) util_calloc ((dstr->buffer_size + BUFFER_CHUNK_SIZE) * (sizeof(char)));
		if (!new_buffer)
		{
			dstr_destroy(dstr);
			return (0);
		}
		ft_memcpy(new_buffer, dstr->buffer, dstr->buffer_size);
		free(dstr->buffer);
		dstr->buffer = new_buffer;
		dstr->buffer_size = dstr->buffer_size + BUFFER_CHUNK_SIZE;
	}
	dstr->buffer[dstr->buffer_index] = ch;
	dstr->buffer_index++;
	return (1);
}

size_t	dstr_length(t_dstr *dstr)
{
	return (dstr->buffer_index);
}

void	dstr_write(t_dstr *dstr, int fd, int new_line)
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
