/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:51:43 by snunez-z          #+#    #+#             */
/*   Updated: 2024/04/12 12:32:38 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# define MAX_OP_FD 10240

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct gnl_bonus
{
	char				buffer [BUFFER_SIZE];
	int					buffer_size;
	int					buffer_index;
	int					fd;
}	t_gnl_bonus;

typedef struct open_files
{
	t_gnl_bonus	buffer[MAX_OP_FD];
	size_t		fd_num;
}	t_open_files;

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
