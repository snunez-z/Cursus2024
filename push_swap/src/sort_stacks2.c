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

static void print_list(t_stack_list *list)
{
	t_stack_list 	*aux;

	aux = list;
	while (aux != NULL)
	{
		printf("%ld ", aux->numbers);
		aux = aux->next;
	}
	printf("\n");
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

void     sort_stacks2(t_stack_list **a,t_stack_list **b)
{
        t_stack_list *node;
       
        while (is_sorted(*a) == 0)
        {
               if(search_largest_number (*a) == 0)
               {
                        pa(a, b);
                        rrb(b);
               }
               node = *a;
               if (node->numbers > node->next->numbers)
                        sa(*a);
               if(search_sortest_number (*a) == 0)
                        pa(a, b);
               ra(a);
        }
        printf("Después de movement: %d\n", is_sorted(*a));
        printf("a: ");
        print_list(*a);
        printf("b: ");
        print_list(*b);
}

       
