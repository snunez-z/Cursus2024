
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	swap(t_stack_list *stack)
{
    long aux;

	if (stack == NULL || stack->next == NULL)
	{
		printf("Error:Stack or node is empty");
		return ;
	}
    aux = stack->numbers;
	stack->numbers = stack->next->numbers;
	stack->next->numbers = aux;
}

