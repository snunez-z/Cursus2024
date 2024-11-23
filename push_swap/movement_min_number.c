
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
#include "move_count.h"

static int     search_sortest_number(t_stack_list  *stack)
{
        int     size;
        int     i;
        t_stack_list    *node;
        int     min;
        int     pos_min;

        size = list_size(stack);
        node = stack;
        i = 0;
        min = node->numbers;
        while(i < size)
        {
                if (node->numbers <= min)
                {
                        min = node->numbers;
                        pos_min = i;  
                }
             
                node = node->next;
                i++;
        }
        return (pos_min);
} 

void     movement_min_number(t_stack_list **a,t_stack_list **b)
{
        int     pos_min;
        int     start;
        int     end;
        int     distance_end;
        int     distance_start;
        t_stack_list    *top_node;
                    
        pos_min = search_sortest_number(*a);
        start = 0;
        end = list_size(*a);
        distance_end = end - pos_min;
        distance_start = pos_min - start;
        if (distance_end > distance_start) 
        {
                while(pos_min > 0)
                {
                        ra(a);
                        top_node = *a;
                        if (top_node->numbers > top_node->next->numbers)
                                sa(*a);
                        pos_min--;
                }
        }
        else 
        {
                while (pos_min < end)
                {
                        rra(a);
                        top_node = *a;
                        if (top_node->numbers >top_node->next->numbers)
                                sa(*a);
                        pos_min++;
                }
        }
        pa(a, b);
        
}    

