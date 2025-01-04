/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 08:51:46 by snunez-z          #+#    #+#             */
/*   Updated: 2024/12/20 15:45:48 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static int	checker_argv(int argc, char **argv, t_stack_list **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (parse_argv(argv[i], a) == 0)
		{
			list_destroy (*a);
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_list	*a;
	t_stack_list	*b;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		if (!checker_argv(argc, argv, &a))
			return (-1);
		if (list_size (a) < 10)
			sort_few_numbers (&a, &b);
		else
		{
			enumerate_index_nodes(a);
			k_sort1(&a, &b);
			k_sort2(&a, &b);
		}
		list_destroy(a);
		list_destroy(b);
		return (0);
	}
}
