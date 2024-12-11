
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
#include "move_count.h"

static int     search_largest_number(t_stack_list  *stack)
{
        int     size;
        int     i;
        t_stack_list    *node;
        int     max;
        int     pos_max;

        size = list_size(stack);
        node = stack;
        i = 0;
        max = node->numbers;
        while(i < size)
        {
                if (node->numbers >= max)
                {
                        max = node->numbers;
                        pos_max = i;  
                }
             
                node = node->next;
                i++;
        }
        return (pos_max);
} 

void     movement_max_number(t_stack_list **a,t_stack_list **b)
{
        int     pos_max;
        int     start;
        int     end;
        int     distance_end;
        int     distance_start;
                            
        pos_max = search_largest_number(*a);
        start = 0;
        end = list_size(*a);
        distance_end = end - pos_max;
        distance_start = pos_max - start;
        if (distance_end > distance_start) 
        {
                while(pos_max > 0)
                {
                        ra(a);
                        pos_max--;
                }
        }
        else 
        {
                while (pos_max < end)
                {
                        rra(a);
                        pos_max++;
                }
        }
        pa(a, b);
        rb(b);
        
}    

