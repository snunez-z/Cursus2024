/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:51:46 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/17 13:52:10 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "push_swap.h"
#include "move_count.h"

static void print_list(t_stack_list *list)
{
	t_stack_list 	*aux;

	aux = list;
	while (aux != NULL)
	{
		printf("%ld ", aux->numbers);
		aux = aux->next;
	}
	printf("\n");
}

static int is_num_repeated(t_stack_list *a, int num)
{
	while(a != NULL)
	{
		if( a->numbers == num)
			return(1);
		a = a->next;
	}
	return (0);
}

static void free_split(char **split)
{
	int index;

	index = 0;
	while(split[index] != NULL)
	{
		free(split[index]);
		index++;
	}
	free(split);
}

static int parse_argv(char *argv, t_stack_list **stack)
{
	char **split;
	int index;
	long num;
	int	atoi_error;

	split = ft_split(argv, ' ');
	if (split == NULL)
		return (0);

	index = 0;
	while (split[index] != NULL)
	{
		num = su_atoi(split[index], &atoi_error);
		if (atoi_error == 1 || is_num_repeated (*stack, num) != 0)
			return (0);

		if (list_append_front(stack, num) == NULL)
		{
			free_split(split);
			// el list_destroy lo hace el "main", no tenemos que hacerlo nosotros aqui
			return (0);
		}
		index++;
	}

	free_split(split);
	return (1);
}

int	main (int argc, char	**argv)
{
	int				i;
	t_stack_list	*a;
	t_stack_list	*b;

    if(argc > 2)
	{
		i = 1;
		a = NULL;
		b = NULL;
		while (i < argc)
		{
			if (parse_argv(argv[i], &a) == 0)
			{
				list_destroy (a);
				list_destroy (b);
				printf("Error\n");
				return (-1);
			}
			i++;
		}
		printf("Antes de hacer nada: ");
		print_list(a);
        
		if (list_size (a) < 10)
			sort_few_numbers (&a, &b);
		else 
		{
			enumerate_index_nodes(a);
			k_sort1(&a, &b);
			k_sort2(&a, &b);
			printf("\n");
			printf("Después del ksort: ");
			print_list(a);
			print_list(b);
		}
		printf ("\n");
		printf("Moves = %d\n", move_count());
		list_destroy(a);
		list_destroy(b);
		return (0);
	}
}
