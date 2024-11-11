#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>

void	rotate_reverse (t_stack_list **stack)
{
    t_stack_list *first_node;
    t_stack_list *last_node;
    t_stack_list *penultimate;

    first_node = *stack;
    penultimate = first_node;

	if (*stack == NULL || list_size(*stack) < 2)
	{
		printf("Error:Stack or node is empty");
		return ;
	}
    while (penultimate->next->next != NULL)
    {
        penultimate = penultimate->next;
    }
	last_node = penultimate->next;
    *stack = last_node;
    penultimate ->next = NULL;
	last_node->next = first_node;
}
