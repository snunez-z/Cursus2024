/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:08:57 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/19 13:43:33 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static int	search_sortest_number(t_stack_list  *stack)
{
	int				size;
	int				i;
	t_stack_list	*node;
	int				min;
	int				pos_min;

	size = list_size(stack);
	node = stack;
	i = 0;
	min = node->numbers;
	while (i < size)
	{
		if (node->numbers <= min)
		{
			min = node->numbers;
			pos_min = i;
		}
		node = node->next;
		i++;
	}
	return (pos_min);
}

void	move_min_number(t_stack_list **a)
{
	int	pos_min;
	int	end;
	int	distance_end;           

	pos_min = search_sortest_number(*a);
	end = list_size(*a);
	distance_end = end - pos_min;
	if (distance_end > pos_min)
	{
		while (pos_min > 0)
		{
			ra(a, 1);
			pos_min--;
		}
	}
	else
	{
		while (pos_min < end)
		{
			rra(a, 1);
			pos_min++;
		}
	}
}    

void	sort_few_numbers(t_stack_list **a, t_stack_list **b)
{
	while (*a != NULL && is_sorted (*a, 1) == 0)
	{
		move_min_number (a);
		pb(a, b, 1);
	}
	move_min_number (a);
	while (*b != NULL)
	pa(a, b, 1);
}
