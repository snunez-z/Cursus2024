/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:46:37 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/19 13:25:28 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_stack_list
{
	long				numbers;
	int					index;
	struct s_stack_list	*next;
}	t_stack_list;

// Stack functions

t_stack_list	*list_append_front(t_stack_list **numbers, long number);
t_stack_list	*list_append_back(t_stack_list **numbers, long number);
void			list_destroy(t_stack_list *numbers);
size_t			list_size(t_stack_list *numbers);
int				su_atoi(const char *str, int *p_error);

// Allowed movements

void			rr(t_stack_list **a, t_stack_list **b, int has_to_write);
void			ra(t_stack_list **a, int has_to_write);
void			rb(t_stack_list **b, int has_to_write);
void			rrr(t_stack_list **a, t_stack_list **b, int has_to_write);
void			rra(t_stack_list **a, int has_to_write);
void			rrb(t_stack_list **b, int has_to_write);
void			pa(t_stack_list **a, t_stack_list **b, int has_to_write);
void			pb(t_stack_list **a, t_stack_list **b, int has_to_write);
void			ss(t_stack_list *a, t_stack_list *b, int has_to_write);
void			sa(t_stack_list *a, int has_to_write);
void			sb(t_stack_list *b, int has_to_write);

// push_swap functions

void			move_min_number(t_stack_list **a);
void			sort_few_numbers(t_stack_list **a, t_stack_list **b);
void			enumerate_index_nodes(t_stack_list *stack);
void			k_sort1(t_stack_list **a, t_stack_list **b);
void			k_sort2(t_stack_list **a, t_stack_list **b);

// checker function

int				parse_argv(char *argv, t_stack_list **stack);
int				is_sorted(t_stack_list *stack, int allow_cut);

// bonus

int read_result_push_swap(t_stack_list **a, t_stack_list **b);

#endif
