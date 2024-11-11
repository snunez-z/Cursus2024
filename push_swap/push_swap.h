
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


void	rotate (t_stack_list **stack);
void	swap(t_stack_list *stack);
void	rotate (t_stack_list **stack);
void	rotate_reverse (t_stack_list **stack);
long	list_stack_pop(t_stack_list	**stack);
void 	list_stack_push(long	num, t_stack_list **stack);

#endif

