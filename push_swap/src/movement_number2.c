
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
static int must_swap(t_stack_list *a)
{
        t_stack_list    *node;
       
        node = a;
        if(node->numbers > node->next->numbers)
                return(1);
        return(0);
}

void     movement_number2(t_stack_list **a,t_stack_list **b)
{
        int     pos_max;
        int     pos_min;
        int     start;
        int     end;
        int     distance_end_max;
        int     distance_end_min;
        int     distance_start_max;
        int     distance_start_min;
                            
        start = 0;
        end = list_size(*a);
        pos_max = search_largest_number(*a);
        pos_min = search_sortest_number (*a);
        distance_start_min = pos_min - start; 
        distance_end_min = end - pos_min; 
        distance_start_max = pos_max - start; 
        distance_end_max = end - pos_max; 

        if (distance_start_min <= distance_end_min && distance_start_min <= distance_start_max && distance_start_min <= distance_end_max)
        {
                while(pos_min > 0)
                {
                        ra (a);
                        if(must_swap(*a) == 1)
                                sa(*a);
                        pos_min--;
                }
                pa(a, b);
        }
        else if (distance_end_min <= distance_start_min && distance_end_min <= distance_start_max && distance_end_min <= distance_end_max)
        {
                while(pos_min < end)
                {
                        rra (a);
                        if(must_swap(*a) == 1)
                                sa(*a);
                        pos_min++;
                }
                pa (a, b);
        }
        else if (distance_start_max <= distance_end_max && distance_start_max <= distance_start_min && distance_start_max <= distance_end_min)
        {
              while(pos_max > 0)
                {
                        ra (a);
                        if(must_swap(*a) == 1)
                             sa(*a);
                        pos_max--;
                } 
                pa (a, b);
                rb (b);
        }
        else if (distance_end_max <= distance_start_max && distance_end_max <= distance_start_min && distance_end_max <= distance_end_min)
        {
                while(pos_max < end)
                {
                        rra (a);
                        if(must_swap(*a) == 1)
                                sa(*a);
                        pos_max++;
                }
                pa (a, b);
                rb (b);
        }
}    


