/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:53:20 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/19 13:23:39 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

static void	rotate (t_stack_list **stack)
{
    t_stack_list *first_node;
    t_stack_list *second_node;
    t_stack_list *last_node;

    if (list_size(*stack) < 2)
		return ;
    first_node = *stack;
    second_node = first_node->next;
    last_node = second_node;
    while (last_node->next != NULL)
        last_node = last_node->next;
    *stack = second_node;
    last_node->next = first_node;
    first_node->next = NULL;
}

void	rr(t_stack_list **a, t_stack_list **b, int has_to_write)
{
	rotate(a);
	rotate(b);
  if (has_to_write)
	    write(1, "rr\n", 3);
}

void	ra(t_stack_list **a, int has_to_write)
{
	rotate(a);
  if (has_to_write)
	  write(1, "ra\n", 3);
}

void	rb(t_stack_list **b, int has_to_write)
{
	rotate(b);
	if (has_to_write)
    write(1, "rb\n", 3);
}

