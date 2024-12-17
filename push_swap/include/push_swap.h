/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:46:37 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/17 12:57:14 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_stack_list
{
    long	numbers;       
    struct s_stack_list *next;
    int index; 
} t_stack_list;

// Stack functions

t_stack_list	*list_append_front(t_stack_list **numbers, long number);
t_stack_list	*list_append_back(t_stack_list **numbers, long number);
void 		list_destroy(t_stack_list *numbers);
size_t 		list_size(t_stack_list *numbers);
int	su_atoi(const char	*str, int *p_error);

// Allowed movements
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

// push_swap functions
void    move_min_number(t_stack_list **a);
void	sort_few_numbers(t_stack_list **a, t_stack_list **b);
void    enumerate_index_nodes(t_stack_list *stack);
void	    k_sort1(t_stack_list **a, t_stack_list **b);
void	    k_sort2(t_stack_list **a, t_stack_list **b);


#endif

