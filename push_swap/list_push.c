
#include "push_swap.h"

void stack_push(long	num, t_stack_list **stack)
{
	list_append (&stack, num);
}

int main(void)
{
    t_list_stack *a;
    
    a =NULL;
    list_append(&a, 10);
    list_append(&a, 30);
    list_append(&a, 50);
    
    stack_push(60, &a);
	return(0);
}

