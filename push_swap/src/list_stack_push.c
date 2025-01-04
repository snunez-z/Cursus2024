/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:50:31 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/19 13:23:39 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "push_swap.h"

static void	list_stack_push(long num, t_stack_list **stack)
{
	list_append_back(stack, num);
}

static long	list_stack_pop(t_stack_list	**stack)
{
	t_stack_list	*first_node;
	long			top_node_content;

	if (*stack == NULL)
	{
		ft_printf("Error:Stack is empty");
		return (-1);
	}
	first_node = *stack;
	top_node_content = first_node->numbers;
	*stack = first_node->next;
	free(first_node);
	return (top_node_content);
}

void	pa(t_stack_list **a, t_stack_list **b, int has_to_write)
{
	long	num;

	num = list_stack_pop(b);
	list_stack_push(num, a);
	if (has_to_write)
		write(1, "pa\n", 3);
}

void	pb(t_stack_list **a, t_stack_list **b, int has_to_write)
{
	long	num;

	num = list_stack_pop(a);
	list_stack_push(num, b);
	if (has_to_write)
		write(1, "pb\n", 3);
}
