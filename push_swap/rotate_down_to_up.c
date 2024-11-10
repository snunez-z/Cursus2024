void	rotate_down_to_up (t_stack_list **stack)
{
    t_list_stack *first_node;
    t_list_stack *last_node;
    t_list_stack *penultimate;

    first_node = *stack;
    penultimate = first_node;
    while (penultimate->next->next != NULL)
    {
        penultimate = penultimate->next;
    }
	last_node = penultimate->next;
    *stack = last_node;
    penultimate ->next = NULL;
	last_node->next = first_node;
}
