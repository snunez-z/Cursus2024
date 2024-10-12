/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:29:26 by snunez-z          #+#    #+#             */
/*   Updated: 2024/04/15 15:43:24 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

typedef struct dstr
{
	char	*buffer;
	size_t	buffer_size;
	size_t	str_len;
}	t_dstr;

char	*get_next_line(int fd);
t_dstr	*dstr_create(void);
char	*dstr_destroy(t_dstr *pdstr);
char	*dstr_reduce(t_dstr *pdstr);
t_dstr	*dstr_append_char(t_dstr *dest_dstr, char ch);

#endif
