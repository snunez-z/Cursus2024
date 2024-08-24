/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:09:55 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 15:10:02 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
}
*/
#include <stdio.h>
#include "sort_list.list.h"

void print_list(t_list *list)
{
	t_list	*iter;
	iter = list;
	while (iter != NULL)
	{
		printf("%d ", iter->data);
		iter = iter->next;
	}
	printf("\n");
}

t_list	*min_search_position(t_list *list)
{
	t_list *aux;
	
	aux = list;
	while(list->next != NULL)
	{
		if (aux->data >= list->next->data)
			aux = list->next;
		list = list->next;
	}
	return (aux);
}

// Con bucle
/*
t_list	*sort_list(t_list	*list)
{
	t_list	*min;
	t_list	*iter;
	int	aux;
	
	if (list == NULL)
		return NULL;

	iter = list;
	while (iter->next != NULL)
	{
		min = min_search_position(iter);
		aux = iter->data;
    	iter->data = min->data;
		min->data = aux;
	    iter = iter->next;

		print_list(list);
	}	

	return (list);
}
*/

// Con recursividad
t_list	*sort_list(t_list	*list)
{
	t_list	*min;
	int	aux;

	if (list == NULL)
		return NULL;

	min = min_search_position(list);
	aux = list->data;
   	list->data = min->data;
	min->data = aux;
	print_list(list);

	sort_list(list->next);
	return list;
}
int main(void)
{
	t_list node1;
	t_list node2;
	t_list node3;
	t_list node4;
	t_list node5;
	t_list	*sorted;

	node1.data = 3;
	node1.next = &node2;
	node2.data = 4;
	node2.next = &node3;
	node3.data = 2;
	node3.next = &node4;
	node4.data = 5;
	node4.next = &node5;
	node5.data = 1;
	node5.next = NULL;

	print_list(&node1);

	sorted = sort_list(&node1);
	print_list(sorted);

	return (0);
}

