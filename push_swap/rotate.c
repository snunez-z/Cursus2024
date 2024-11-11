#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	rotate (t_stack_list **stack)
{
    t_stack_list *first_node;
    t_stack_list *second_node;
    t_stack_list *last_node;

    if (*stack == NULL || list_size(*stack) < 2)
	{
		printf("Error:Stack or node is empty");
		return ;
	}
    first_node = *stack;
    second_node = first_node->next;

    last_node = first_node;
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }

    *stack = second_node;
    last_node->next = first_node;
    first_node->next = NULL;
}
