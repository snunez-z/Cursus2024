/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:21:54 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/08 09:31:23 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dstr.h"
#include "list.h"

static t_list	*create_node(t_dstr *line)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->line = line;
	node->next = NULL;
	return (node);
}

t_list	*list_append(t_list *list, t_dstr *line)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = create_node(line);
	if (!new_node)
	{
		dstr_destroy(line);
		list_destroy(list);
		return (NULL);
	}
	if (list == NULL)
		return (new_node);
	last_node = list;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
	return (list);
}

void	list_destroy(t_list *list)
{
	t_list	*aux;

	while (list != NULL)
	{
		dstr_destroy(list->line);
		aux = list;
		list = list->next;
		free(aux);
	}
}

size_t	list_size(t_list *list)
{
	size_t	size;

	size = 0;
	while (list != NULL)
	{
		size++;
		list = list->next;
	}
	return (size);
}

t_dstr	*list_get(t_list *list, size_t pos)
{
	while (list != NULL && pos > 0)
	{
		list = list->next;
		pos--;
	}
	if (!list)
		return (NULL);
	return (list->line);
}
