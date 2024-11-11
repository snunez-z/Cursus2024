
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


long	list_stack_pop(t_stack_list	**stack)
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
/*int main()
{
    t_stack_list *stack;
	long value;

	stack = NULL;
    t_stack_list *node1 = (t_stack_list *)malloc(sizeof(t_stack_list));
    node1->numbers = 10;
    node1->next = NULL;

    t_stack_list *node2 = (t_stack_list *)malloc(sizeof(t_stack_list));
    node2->numbers = 20;
    node2->next = node1;  
    stack = node2;  

    // Probar stack_pop
    value = stack_pop(&stack);
    printf("Popped value: %ld\n", value);  // Debería imprimir 20

    value = stack_pop(&stack);
    printf("Popped value: %ld\n", value);  // Debería imprimir 10

    value = stack_pop(&stack);
    printf("Popped value: %ld\n", value);  // Debería imprimir -1 (Error)

    return 0;
}*/