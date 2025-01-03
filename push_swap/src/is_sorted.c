
#include <stdlib.h>
#include "push_swap.h"

int is_sorted(t_stack_list *stack, int allow_cut)
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
                return (1); // todos estaban ordenados
        if (!allow_cut)
                return(0);
        number = node->numbers;
        node = node->next;
        while(node != NULL && node->numbers > number) // no esta ordenado porque el ultimo de los numeros es mas grande que el primero
        {
                number = node->numbers;
                node = node->next;
        }
        return (node == NULL && number < stack->numbers);
}
