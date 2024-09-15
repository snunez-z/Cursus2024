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
#include <stdio.h>
#include "sort_list.list.h"

static int ascending(int a, int b)
{
	if (a <= b)
		return 1;
	else
		return 0;
}

static int descending(int a, int b)
{
	if (a >= b)
		return 1;
	else
		return 0;
}

static int peers_first(int a, int b)
{
	if (a % 2 == 0 && b % 2 == 0)
		return (a <= b);
	if (a % 2 == 0)
		return 1;
	if (b % 2 == 0)
		return 0;
	return (a <= b);
}
static t_list	*best_search_order(t_list *list, int (*cmp)(int,int))
{
	t_list *best;
	
	best = list;
	while(list->next != NULL)
	{
		if ((*cmp)(best->data, list->next->data) == 0)
			best = list->next;
		list = list->next;
	}
	return (best);
}
// Con recursividad
t_list	*sort_list(t_list	*list, int (*cmp)(int,int))
{
	t_list	*best;
	int	aux;

	if (list == NULL)
		return NULL;

	best = best_search_order(list, cmp);
	aux = list->data;
   	list->data = best->data;
	best->data = aux;

	sort_list(list->next, cmp);
	return list;
}
/* To check the function
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

	sorted = sort_list(&node1, ascending);
	print_list(sorted);

	sorted = sort_list(&node1, descending);
	print_list(sorted);

	sorted = sort_list(&node1, pares_primero);
	print_list(sorted);

	return (0);
}*/

