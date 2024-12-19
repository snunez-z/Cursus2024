/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:08:57 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/19 13:43:33 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static  int is_sorted(t_stack_list *stack)
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
                return (1);
        number = node->numbers;
        node = node->next;
        while(node != NULL && node->numbers > number)
        {
                number = node->numbers;
                node = node->next;
        }
        return (node == NULL && number < stack->numbers);
}
static int     search_sortest_number(t_stack_list  *stack)
{
        int     size;
        int     i;
        t_stack_list    *node;
        int     min;
        int     pos_min;

        size = list_size(stack);
        node = stack;
        i = 0;
        min = node->numbers;
        while(i < size)
        {
                if (node->numbers <= min)
                {
                        min = node->numbers;
                        pos_min = i;  
                }
             
                node = node->next;
                i++;
        }
        return (pos_min);
} 

void     move_min_number(t_stack_list **a)
{
        int     pos_min;
        int     start;
        int     end;
        int     distance_end;
        int     distance_start;
                           
        pos_min = search_sortest_number(*a);
        start = 0;
        end = list_size(*a);
        distance_end = end - pos_min;
        distance_start = pos_min - start;
        if (distance_end > distance_start) 
        {
                while(pos_min > 0)
                {
                        ra(a);
                        pos_min--;
                }
        }
        else 
        {
                while (pos_min < end)
                {
                        rra(a);
                        pos_min++;
                }
        }
 }    

void     sort_few_numbers (t_stack_list **a,t_stack_list **b)
{
        while(*a != NULL && is_sorted (*a) == 0)
        {
                move_min_number (a);
                pa(a, b);
        }
        move_min_number (a);
        while (*b != NULL)
                pb(b,a);
}
