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


void     sort_stacks(t_stack_list **a,t_stack_list **b)
{
        int     size;
        int     i;

        size= list_size (*a);
        i = 0;
        while (i < size && is_sorted(*a) == 0)
        {
               movement_number2(a, b);
               i++;
        }
        printf("Después de movement: %d %d\n", i, is_sorted(*a));
        printf("a: ");
        print_list(*a);
        printf("b: ");
        print_list(*b);

        while (i > 0)
        {
              pb(b, a);
              i--;
        }     
        printf("Después de mover todo a a\n");
        printf("a: ");
        print_list(*a);
}
