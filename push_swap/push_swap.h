
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_stack_list
{
    long	numbers;       
    struct s_stack_list *next; 
} t_stack_list;

t_stack_list	*list_append(t_stack_list **numbers, long number);
void 		list_destroy(t_stack_list *numbers);
size_t 		list_size(t_stack_list *numbers);
size_t 		*list_get(t_stack_list *numbers, long pos);
int		su_atoi(const char *str);

#endif

