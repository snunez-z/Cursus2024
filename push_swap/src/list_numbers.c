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
/*
size_t *list_get(t_stack_list *numbers, size_t pos)
{
    while (numbers != NULL && pos > 0)
	{
        numbers = numbers->next;
        pos--;
    }
    if (!numbers) return NULL;
    return numbers->numbers;  // Retorna el puntero al número en la posición
}

int main()
{
    t_stack_list *list;
	
	list = NULL;

    list = list_append(&list, 10);
    list = list_append(&list, 20);
    list = list_append(&list, 30);

     printf("Tamaño de la lista: %zu\n", list_size(list));

    size_t *number = list_get(list, 1);
    if (number)
	    printf("Número en la posición 1: %zu\n", *number);
    list_destroy(list);
    return (0);
}
*/
