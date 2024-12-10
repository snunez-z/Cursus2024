
#include "push_swap.h"
#include <stdio.h>

/* Rango 0 = (1 - 99)
Rango 1 = (100 - 199)
Rango 2 =  (200 - 299)
Rango 3 = (300 - 399)
Rango 4 = = (400 - 500)*/


int get_range(int value, int min, int max, int k) 
{
    int range_size = (max - min + 1) / k;
    return (value - min) / range_size;

void	ksort(t_stack_list **a, t_stack_list **b)
{
	t_stack_list	*node;
    int index;

	index = 1;
	node = *a;
	while (index < 10)
	{
		if (node->next != NULL && get_range(node->numbers, 1, 500, 5) == 0)
		{
			movement_min_number(a, b);
			sb(a,b);
		}
		else
		{

		}
		
		node = node->next
		index++;
	}
}

