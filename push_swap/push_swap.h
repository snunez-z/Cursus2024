
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_stack_list
{
    size_t *numbers;       
    struct s_stack_list *next; 
} t_stack_list;

t_stack_list	*list_append(t_stack_list **numbers, size_t number);
void 			list_destroy(t_stack_list *numbers);
size_t 			list_size(t_stack_list *numbers);
size_t 			*list_get(t_stack_list *numbers, size_t pos);

#endif

