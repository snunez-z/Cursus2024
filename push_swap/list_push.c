
#include "push_swap.h"


void stack_push(long	num, t_stack_list *stack)
{
	t_stack_list	*new_node;
	t_stack_list	*first_node;
	
	first_node = *stack;
	new_node = list_append (&stack, new_node->numbers);
	first_node = *new_node;
}


