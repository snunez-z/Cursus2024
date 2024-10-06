/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:16:25 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 09:49:09 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Provides functions to handle character buffers that will grow automatically
 * as new characters are appended.
 */
#ifndef DSTR_H
# define DSTR_H

# include <stddef.h>

/*
 * Fields:
 * "buffer" is the actual character buffer where we stored the characters
 * "buffer_size" is the maximum number of characters that fit into the buffer.
 *               When this buffer is full (by consecutive calls to
 *               dstr_append_char) it will try to grow bigger.
 * "buffer_index" is the actual number of characters we have appended. This
 *                value will always be smaller or equals than "buffer_size".
 */
typedef struct s_dstr
{
	char	*buffer;
	size_t	buffer_size;
	size_t	buffer_index;
}	t_dstr;

/*
 * Allocates a "t_dstr" structure, and initializes it's internal buffer.
 * "buffer_index" will be zero because no character has been appended yet.
 * Returns the pointer to allocated "t_dstr" structure
 */
t_dstr	*dstr_create(void);

/*
 * Frees all the memory held by a "t_dstr" instance. This includes the internal
 * "buffer" and the memory allocated for the "t_dstr" structure itself.
 * Parameters:
 * "dstr" the pointer to the "t_dstr" instance to free
 */
void	dstr_destroy(t_dstr *dstr);

/*
 * Return one character within a "t_dstr" instance's internal buffer.
 * Optionally it can be changed too.
 * Parameters:
 * "dstr" the "t_dstr" instance to get/change the character from
 * "pos" the index of the character to get/change
 * "ch" if zero, then the character at position "pos" is not modified,
 *      otherwise, the character at position "pos" will be replaced by this one
 *
 * Returns the character that WAS at position "pos" before replacing it
 */
char	dstr_char_at(t_dstr *dstr, size_t pos, char ch);

/*
 * Appends one character a "t_dstr" instance's internal "buffer". As a
 * consequence of this, the buffer may need to grow.
 * Parameters:
 * "dstr" the "t_dstr" instance to append the character to its internal "buffer"
 * "ch" the character to append
 *
 * Returns:
 * true (non-zero) if the character was successfully appended
 * false (zero) if in order to append the character, the buffer needed to grow,
 *              but the "malloc" failed. In this case, there is no need to call
 *              "dstr_destroy" because if "malloc" fails, everything will be
 *              cleaned up for you.
 */
int		dstr_append_char(t_dstr *dstr, char ch);

/*
 * Returns the number of characters we have appended to a "t_dstr" instance's
 * internal buffer.
 * Parameters:
 * "dstr" the "t_dstr" instance for which we need to know the number of
 *        appended characters.
 */
size_t	dstr_length(t_dstr *dstr);

#endif
