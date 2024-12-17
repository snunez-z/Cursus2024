/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:49:29 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/17 09:01:51 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
#include "move_count.h"

void	enumerate_index_nodes(t_stack_list *stack)
{
        t_stack_list    *aux;
        t_stack_list  *iterator;
        int     pos_ordered;
        
        iterator = stack;
        while(iterator != NULL)
        {
                aux = stack;
                pos_ordered = 0;
                while(aux!= NULL)
                {
                        if (aux->numbers < iterator->numbers)
                                pos_ordered++;
                        aux = aux->next;
                }
                iterator->index = pos_ordered;
                iterator = iterator->next;
        }
}

static	int sqrt_num(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	return (i);
}       
        
void	k_sort1(t_stack_list **a, t_stack_list **b)
{
	int     size;
        int     sqrt;
        int     b_nodes;

        size = list_size (*a); 
        sqrt = sqrt_num(size); 
        b_nodes = 0;
        while(*a != NULL)//Mientras no este vacia
        {
                if((*a)->index <= b_nodes)
                {
                        pa(a, b);
                        rb(b);
                        b_nodes++;
                }
                else if((*a)->index <= (b_nodes + sqrt))
                {
                        pa(a, b);
                        b_nodes++;
                }
                else
                        ra(a);
        }
}

static int	search_max_num(t_stack_list *stack)
{
	int     pos_max;
        t_stack_list    *node;
        int size;

        size =list_size (stack);
        pos_max = 0;
        node = stack;
        while (pos_max <= (size-1))
        {
                if(node->index ==(size -1))
                        return(pos_max);
                node = node->next;
                pos_max ++;   
        }
        return(0);
}

void	k_sort2(t_stack_list **a, t_stack_list **b)
{
	int     pos_max;
        int     end;
        int     distance_end;
        int     distance_start;
                            
        while (*b != NULL)// este vacia la pila
        {
                pos_max = search_max_num(*b);
                end = list_size(*b);
                distance_end = end - pos_max;
                distance_start = pos_max - 0;
                if (distance_end >= distance_start) 
                {
                        while(pos_max > 0)
                        {
                                rb(b);
                                pos_max--;
                        }       
                }
                else 
                {
                        while (pos_max < end)
                        {
                                rrb(b);
                                pos_max++;
                        }
                }
                pb(b, a);
        }
}

     
        
        
        
        
        
        
        
        
        
        
