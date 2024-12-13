
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
#include "move_count.h"

int	enumerate_index_nodes(t_stack_list *stack)
{
	int     size;
        t_stack_list    *aux;
        t_stack_list  iterator;
        int     pos_ordered;
        
        size = list_size(stack);
        iterator = stack;
        while(iterator != NULL)
        {
                aux = stack;
                pos_ordered = 0;
                while(aux!= NULL)
                {
                        if (aux->numbers < iterator->numbers)
                                pos_ordered++;
                        aux = aux->next;
                }
                iterator->index = pos_ordered;
                iterator = iterator->next;
        }
}

 int	sqrt_num(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	return (i);
}       
        
int	k_sort1(t_stack_list **a, t_stack **b)
{
	int     size;
        int     sqrt;
        int     b_nodes;

        size = list_size (stack); 
        sqrt = sqrt_num(size); 
        b_nodes = 0;
        while(stack != NULL)//Mientras no este vacia
        {
                if(stack->index <= (b_nodes + sqrt))
                        pa(a, b);
                else
                        ra(a);
        }
}

int	k_sort2(t_stack_list **a, t_stack **b)
{
	int     pos_max;
        
        pos_max = b->index
}


     
        
        
        
        
        
        
        
        
        
        