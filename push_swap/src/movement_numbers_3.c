
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
#include "move_count.h"

int	enumerate_index_nodes(t_stack_list *stack)
{
	int     size;
        t_stack_list    *aux;
        t_stack_list  *iterator;
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

 static	sqrt_num(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	return (i);
}       
        
void	k_sort1(t_stack_list **a, t_stack_list **b)
{
	int     size;
        int     sqrt;
        int     b_nodes;

        size = list_size (stack); 
        sqrt = sqrt_num(size); 
        b_nodes = 0;
        while(a != NULL)//Mientras no este vacia
        {
                if(stack->index <= (b_nodes + sqrt))
                        pa(a, b);
                else
                        ra(a);
        }
}

static int	search_max_num(t_stack_list *stack)
{
	int     pos_max;
        t_stack_list    *node;
        int size;

        size =list_size (stack);
        pos_max = 0;
        node = stack;
        while (pos_max <= (size-1))
        {
                if(node->index ==(size -1))
                        return(pos_max);
                node = node->next;
                pos_max ++;   
        }
        return(0);
}

void	k_sort2(t_stack_list **a, t_stack **b)
{
	int     pos_max;
        int     start;
        int     end;
        int     distance_end;
        int     distance_start;
                            
        pos_max = search_max_num(b);
        start = 0;
        end = list_size(*b);
        distance_end = end - pos_max;
        distance_start = pos_max - start;
        while( b!= NULL)// este vacia la pila
        {
                if (distance_end >= distance_start) 
                {
                        while(pos_max > 0)
                        {
                        rb(b);
                        pos_max--;
                         }       
                }
                else 
                {
                        while (pos_max < end)
                        {
                                rrab(b);
                                pos_max++;
                        }
                }
                pa(b, a);
        }
       	return (0);
}

     
        
        
        
        
        
        
        
        
        
        