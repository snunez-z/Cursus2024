#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

static  int is_sorted(t_stack_list *stack)
{
        t_stack_list *node;
        int number;

        if (list_size(stack) < 2)
                return (1);
        node = stack;
        number = node->numbers;
        node = node->next;
        while(node != NULL && node->numbers > number)
        {
                number = node->numbers;
                node = node->next;
        }
        if (node == NULL)
                return (1);
        number = node->numbers;
        node = node->next;
        while(node != NULL && node->numbers > number)
        {
                number = node->numbers;
                node = node->next;
        }
        return (node == NULL && number < stack->numbers);
}

void     sort_stacks(t_stack_list **a,t_stack_list **b)
{
        int     size;
        int     i;

        size= list_size (*a);
        i = 0;
        while (i < size && is_sorted(*a) == 0)
        {
               movement_min_number(a, b);
               i++;
        }
        while (i > 0)
        {
              pb(b, a);
              i--;
        }     
}
