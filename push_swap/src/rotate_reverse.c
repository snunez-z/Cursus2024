/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:53:05 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/19 13:23:39 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "push_swap.h"

static void	rotate_reverse(t_stack_list **stack)
{
	t_stack_list	*first_node;
	t_stack_list	*last_node;
	t_stack_list	*penultimate;

	first_node = *stack;
	penultimate = first_node;
	if (list_size(*stack) < 2)
	{
		ft_printf("Error:Stack or node is empty");
		return ;
	}
	while (penultimate->next->next != NULL)
		penultimate = penultimate->next;
	last_node = penultimate->next;
	*stack = last_node;
	penultimate ->next = NULL;
	last_node->next = first_node;
}

void	rrr(t_stack_list **a, t_stack_list **b, int has_to_write)
{
	rotate_reverse(a);
	rotate_reverse(b);
	if (has_to_write)
		write (1, "rr\n", 3);
}

void	rra(t_stack_list **a, int has_to_write)
{
	rotate_reverse(a);
	if (has_to_write)
		write (1, "rra\n", 4);
}

void	rrb(t_stack_list **b, int has_to_write)
{
	rotate_reverse(b);
	if (has_to_write)
		write(1, "rrb\n", 4);
}
