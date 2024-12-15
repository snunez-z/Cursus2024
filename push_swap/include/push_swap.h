
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_stack_list
{
    long	numbers;       
    struct s_stack_list *next;
    int index; 
} t_stack_list;

t_stack_list	*list_append_front(t_stack_list **numbers, long number);
t_stack_list	*list_append_back(t_stack_list **numbers, long number);
void 		list_destroy(t_stack_list *numbers);
size_t 		list_size(t_stack_list *numbers);
size_t 		*list_get(t_stack_list *numbers, long pos);
int		su_atoi(const char *str);


void	rr(t_stack_list **a, t_stack_list **b);
void	ra(t_stack_list **a);
void	rb(t_stack_list **b);
void    rrr(t_stack_list **a, t_stack_list **b);
void    rra(t_stack_list **a);
void    rrb(t_stack_list **b);
void pa(t_stack_list **a, t_stack_list **b);
void pb(t_stack_list **b, t_stack_list **a);
void ss(t_stack_list *a, t_stack_list *b);
void sa(t_stack_list *a);
void sb(t_stack_list *b);

void    movement_min_number(t_stack_list **a, t_stack_list **b);
void    movement_max_number(t_stack_list **a,t_stack_list **b);
void    movement_numbers(t_stack_list **a,t_stack_list **b);
void    movement_number2(t_stack_list **a,t_stack_list **b);
void    movement_number_3(t_stack_list **a,t_stack_list **b);
void    sort_stacks(t_stack_list **a,t_stack_list **b);
void    sort_stacks2(t_stack_list **a,t_stack_list **b);

#endif

