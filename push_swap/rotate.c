#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	rotate (t_stack_list **stack)
{
    t_stack_list *first_node;
    t_stack_list *second_node;
    t_stack_list *last_node;

    if (list_size(*stack) < 2)
	{
		printf("Error:Stack or node is empty");
		return ;
	}
    first_node = *stack;
    second_node = first_node->next;
    last_node = second_node;
    while (last_node->next != NULL)
        last_node = last_node->next;
    *stack = second_node;
    last_node->next = first_node;
    first_node->next = NULL;
}

void	rr(t_stack_list **a, t_stack_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	ra(t_stack_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

