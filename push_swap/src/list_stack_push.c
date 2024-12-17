/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:50:31 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/17 08:50:40 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "move_count.h"

static void list_stack_push(long	num, t_stack_list **stack)
{
	list_append_back (stack, num);
}

static long	list_stack_pop(t_stack_list	**stack)
{
	t_stack_list	*first_node;
	long			top_node_content;	

	if (*stack == NULL)
	{
		printf("Error:Stack is empty");
		return (-1);
	}
	first_node = *stack;
	top_node_content = first_node->numbers;
	*stack = first_node->next;
	free(first_node);

return(top_node_content);
}

void pa(t_stack_list **a, t_stack_list **b)
{
    long num;
	    
  	num = list_stack_pop(a);
    list_stack_push(num, b);
    write(1, "pa\n", 3);
	move_inc();
}

void pb(t_stack_list **b, t_stack_list **a)
{
    long num;
    
    num = list_stack_pop(b);
    list_stack_push(num, a);
    write(1, "pb\n", 3);
	move_inc();
}


