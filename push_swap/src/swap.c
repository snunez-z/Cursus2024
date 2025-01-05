/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:54:45 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/19 13:23:39 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "push_swap.h"

static void	swap(t_stack_list **stack)
{
	t_stack_list	*first_node;
	t_stack_list	*second_node;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		ft_printf("Error:Stack or node is empty");
		return ;
	}
	first_node = *stack;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
}

void	ss(t_stack_list **a, t_stack_list **b, int has_to_write)
{
	swap(a);
	swap(b);
	if (has_to_write)
		write(1, "ss\n", 3);
}

void	sa(t_stack_list **a, int has_to_write)
{
	swap(a);
	if (has_to_write)
		write(1, "sa\n", 3);
}

void	sb(t_stack_list **b, int has_to_write)
{
	swap(b);
	if (has_to_write)
		write(1, "sb\n", 3);
}
