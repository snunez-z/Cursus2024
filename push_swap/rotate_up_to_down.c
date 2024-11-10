void	rotate_up (t_stack_list **stack)
{
    t_list_stack *first_node;
    t_list_stack *second_node;
    t_list_stack *last_node;

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
