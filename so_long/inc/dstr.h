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

#ifndef DSTR_H
# define DSTR_H

# include <stddef.h>

typedef struct s_dstr
{
	char	*buffer;
	size_t	buffer_size;
	size_t	buffer_index;
}	t_dstr;

t_dstr	*dstr_create(void);
void	dstr_destroy(t_dstr *dstr);
char	dstr_char_at(t_dstr *dstr, size_t pos, char ch);
int		dstr_append_char(t_dstr *dstr, char ch);
size_t	dstr_length(t_dstr *dstr);

#endif
