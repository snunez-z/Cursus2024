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
#include "move_count.h"

static void	swap(t_stack_list *stack)
{
    long aux;

	if (stack == NULL || stack->next == NULL)
	{
		ft_printf("Error:Stack or node is empty");
		return ;
	}
    aux = stack->numbers;
	stack->numbers = stack->next->numbers;
	stack->next->numbers = aux;
}

void ss(t_stack_list *a, t_stack_list *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	move_inc();
}

void sa(t_stack_list *a)
{
	swap(a);
	write(1, "sa\n", 3);
	move_inc();
}

void sb(t_stack_list *b)
{
	swap(b);
	write(1, "sb\n", 3);
	move_inc();
}



