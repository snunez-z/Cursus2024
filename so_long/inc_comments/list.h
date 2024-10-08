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

/*
 * This module provides a list of "t_dstr" instances.
 * This will allow us to store each line of the map in a node of the list
 * An empty list is a "t_list *" variable pointing to NULL
 */

#ifndef LIST_H
# define LIST_H

# include <stddef.h>
# include "dstr.h"

/*
 * "line" the line stored in the list node
 * "next" the pointer to the next list node (next line)
 */
typedef struct s_list
{
	t_dstr			*line;
	struct s_list	*next;
}	t_list;

/*
 * Appends a node to a list
 * Parameters:
 * "list": The list to append a new node to. This parameter can be NULL
 *         if the list is initially empty.
 * "line": The data of the node to add. This means that a new "t_list*" will be
 *         allocated and this "line" will be assigned to its "line" field.
 *
 * Returns: the new first node of the list.
 */
t_list	*list_append(t_list *list, t_dstr *line);

/*
 * Frees the memory allocated by all the nodes in the given "list". This includes
 * the "t_dstr" instance inside each node.
 * Parameters:
 * "list" the list to free. It can be NULL if the list is empty, in which case
 *        nothing will be done.
 */
void	list_destroy(t_list *list);

/*
 * Returns the number of nodes the given "list" has
 * Parameters:
 * "list": The list to obtain its size. If NULL, zero will be returned
 */
size_t	list_size(t_list *list);

/*
 * Returns the "line" field in one node of the list
 * Parameters:
 * - "list": The list to get the node from.
 * - "pos": The index of the node we want to obtain the line from
 */
t_dstr	*list_get(t_list *list, size_t pos);

#endif
