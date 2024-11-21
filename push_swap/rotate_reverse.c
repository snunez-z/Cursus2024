#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

static void	rotate_reverse (t_stack_list **stack)
{
    t_stack_list *first_node;
    t_stack_list *last_node;
    t_stack_list *penultimate;

    first_node = *stack;
    penultimate = first_node;

	if (list_size(*stack) < 2)
	{
		printf("Error:Stack or node is empty");
		return ;
	}
    while (penultimate->next->next != NULL)
        penultimate = penultimate->next;    
    last_node = penultimate->next;
    *stack = last_node;
    penultimate ->next = NULL;
	last_node->next = first_node;
}

void rrr(t_stack_list **a, t_stack_list **b)
{
    rotate_reverse(a);
    rotate_reverse(b);
    write(1,"rr\n", 3);
}

void rra(t_stack_list **a)
{
    rotate_reverse(a);
    write(1,"rra\n", 4);
}

void rrb(t_stack_list **b)
{
    rotate_reverse(b);
    write(1,"rrb\n", 4);
}