/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 09:21:54 by snunez-z          #+#    #+#             */
/*   Updated: 2024/10/04 12:38:37 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

static t_list	*create_node(void *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

t_list	*list_append(t_list *list, void *data, void (*free_data)(void*))
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = create_node(data);
	if (!new_node)
	{
		free_data(data);
		list_destroy(list, free_data);
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

void	list_destroy(t_list *list, void (*free_data)(void*))
{
	t_list	*aux;

	while (list != NULL)
	{
		free_data(list->data);
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

void	*list_get(t_list *list, size_t pos)
{
	while (list != NULL && pos > 0)
	{
		list = list->next;
		pos--;
	}
	if (!list)
		return (NULL);
	return (list->data);
}
