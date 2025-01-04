/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enumerate_index_nodes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:49:29 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/19 13:02:18 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	enumerate_index_nodes(t_stack_list *stack)
{
	t_stack_list	*aux;
	t_stack_list	*iterator;
	int				pos_ordered;

	iterator = stack;
	while (iterator != NULL)
	{
		aux = stack;
		pos_ordered = 0;
		while (aux != NULL)
		{
			if (aux->numbers < iterator->numbers)
				pos_ordered++;
			aux = aux->next;
		}
		iterator->index = pos_ordered;
		iterator = iterator->next;
	}
}
