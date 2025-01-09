/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:52:35 by snunez-z          #+#    #+#             */
/*   Updated: 2025/01/09 13:53:37 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	is_sorted(t_stack_list *stack, int allow_cut)
{
	t_stack_list	*node;
	int				number;

	if (list_size(stack) < 2)
		return (1);
	node = stack;
	number = node->numbers;
	node = node->next;
	while (node != NULL && node->numbers > number)
	{
		number = node->numbers;
		node = node->next;
	}
	if (node == NULL)
		return (1);
	if (!allow_cut)
		return (0);
	number = node->numbers;
	node = node->next;
	while (node != NULL && node->numbers > number)
	{
		number = node->numbers;
		node = node->next;
	}
	return (node == NULL && number < stack->numbers);
}
