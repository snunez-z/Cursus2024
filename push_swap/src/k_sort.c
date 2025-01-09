/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:49:29 by snunez-z          #+#    #+#             */
/*   Updated: 2025/01/09 13:55:44 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static int	sqrt_num(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	return (i);
}

void	k_sort1(t_stack_list **a, t_stack_list **b)
{
	int	size;
	int	sqrt;
	int	b_nodes;

	size = list_size (*a);
	sqrt = sqrt_num(size);
	b_nodes = 0;
	while (*a != NULL)
	{
		if ((*a)->index <= b_nodes)
		{
			pb(a, b, 1);
			rb(b, 1);
			b_nodes++;
		}
		else if ((*a)->index <= (b_nodes + sqrt))
		{
			pb(a, b, 1);
			b_nodes++;
		}
		else
			ra(a, 1);
	}
}

static int	search_max_num(t_stack_list *stack)
{
	int				pos_max;
	t_stack_list	*node;
	int				size;

	size = list_size (stack);
	pos_max = 0;
	node = stack;
	while (node != NULL)
	{
		if (node->index == (size -1))
			return (pos_max);
		node = node->next;
		pos_max++;
	}
	return (0);
}

static void	move_node_to_top(t_stack_list **stack, int pos)
{
	int	size;

	size = list_size(*stack);
	if ((size - pos) >= pos)
	{
		while (pos > 0)
		{
			rb(stack, 1);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rrb(stack, 1);
			pos++;
		}
	}
}

void	k_sort2(t_stack_list **a, t_stack_list **b)
{
	int	pos_max;

	while (*b != NULL)
	{
		pos_max = search_max_num(*b);
		move_node_to_top(b, pos_max);
		pa(a, b, 1);
	}
}
