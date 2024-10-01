#include <stdlib.h>
#include "list.h"

static list_t	*create_node(void *data)
{
	list_t	*node;

	node = malloc(sizeof(list_t));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

list_t*	list_append(list_t *list, void *data, void (*free_data)(void*))
{
	list_t	*new_node;
	list_t	*last_node;

	new_node = create_node(data);
	if (!new_node)
	{
		free_data(data);
		list_destroy(list, free_data);
		return (NULL);
	}
	if (list == NULL)
		return new_node;
	last_node = list;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
	return list;
}

void	list_destroy(list_t *list, void (*free_data)(void*))
{
	list_t	*aux;

	while (list != NULL)
	{
		free_data(list->data);
		aux = list;
		list = list->next;
		free(aux);
	}
}

size_t	list_size(list_t *list)
{
	size_t size;

	size = 0;
	while(list != NULL)
	{
		size++;
		list = list->next;
	}
	return size;
}

void	*list_get(list_t *list, size_t pos)
{
	while (list != NULL && pos > 0)
	{
		list = list->next;
		pos--;
	}
	if (!list)
		return NULL;
	return list->data;
}
