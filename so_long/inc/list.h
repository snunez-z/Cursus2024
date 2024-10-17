/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:18:33 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/08 09:31:23 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIST_H
# define LIST_H

# include <stddef.h>
# include "dstr.h"

typedef struct s_list
{
	t_dstr			*line;
	struct s_list	*next;
}	t_list;

t_list	*list_append(t_list *list, t_dstr *line);
void	list_destroy(t_list *list);
size_t	list_size(t_list *list);
t_dstr	*list_get(t_list *list, size_t pos);

#endif
