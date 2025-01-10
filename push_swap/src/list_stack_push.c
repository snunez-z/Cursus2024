/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:50:31 by snunez-z          #+#    #+#             */
/*   Updated: 2025/01/09 13:13:00 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

static void	move_top_node(t_stack_list	**from, t_stack_list	**to)
{
	t_stack_list	*first_node;

	if (*from == NULL)
		return ;
	first_node = *from;
	*from = first_node->next;
	first_node->next = *to;
	*to = first_node;
}

void	pa(t_stack_list **a, t_stack_list **b, int has_to_write)
{
	move_top_node(b, a);
	if (has_to_write)
		write(1, "pa\n", 3);
}

void	pb(t_stack_list **a, t_stack_list **b, int has_to_write)
{
	move_top_node(a, b);
	if (has_to_write)
		write(1, "pb\n", 3);
}
