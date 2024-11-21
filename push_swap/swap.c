
#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static void	swap(t_stack_list *stack)
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

void ss(t_stack_list *a, t_stack_list *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void sa(t_stack_list *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void sb(t_stack_list *b)
{
	swap(b);
	write(1, "sb\n", 3);
}



