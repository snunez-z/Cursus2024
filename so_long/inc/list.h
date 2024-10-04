/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:18:33 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 10:10:00 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stddef.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

t_list	*list_append(t_list *list, void *data, void (*free_data)(void*));
void	list_destroy(t_list *list, void (*free_data)(void*));
size_t	list_size(t_list *list);
void	*list_get(t_list *list, size_t pos);

#endif
