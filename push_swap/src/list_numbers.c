#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"


static t_stack_list *create_node(long number)
{
    t_stack_list *node;

	node = (t_stack_list *) malloc(sizeof(t_stack_list));
    if (!node) 
		return (NULL);

    node->numbers = number;  
    node->next = NULL;
    return (node);
}

t_stack_list *list_append_front(t_stack_list **numbers, long number)
 {
    t_stack_list *new_node;
	t_stack_list *last_node;
	
	new_node = create_node(number);
    if (!new_node)
		return (NULL);

    if (*numbers == NULL)
	    *numbers = new_node; 
    else
	{
        last_node = *numbers;
        while (last_node->next != NULL) 
	        last_node = last_node->next; 
        last_node->next = new_node; 
    }
    return (*numbers);
}

t_stack_list *list_append_back(t_stack_list **numbers, long number)
 {
    t_stack_list *new_node;
	t_stack_list *first_node;
	
	first_node = *numbers;
    new_node = create_node(number);
    if (!new_node)
		return (NULL);
    if(*numbers == NULL)
        *numbers = new_node;
    else
    {
        *numbers = new_node;
        new_node->next = first_node;
    }
    return (*numbers);
 }
    
void list_destroy(t_stack_list *numbers)
{
    t_stack_list *aux;

    while (numbers != NULL)
	{
        aux = numbers;
        numbers = numbers->next;
        free(aux);           
    }
}
size_t list_size(t_stack_list *numbers)
{
    size_t size;
	
	size = 0;
    while (numbers != NULL)
	{
        size++;
        numbers = numbers->next;
    }
    return size;
}
