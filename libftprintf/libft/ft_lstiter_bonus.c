/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 07:55:05 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 18:30:55 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*iter;

	if (lst == NULL)
		return ;
	iter = lst;
	while (iter != NULL)
	{
		(*f)(iter->content);
		iter = iter->next;
	}
}
/*
static void	test_function(void	*content)
{
	long	num;

	num = (long)content;
	if (num == 13)
		printf("Mala suerte");
	printf("%ld ", (long)content);
}

int	main(void)
{
	int		num_elements;
	t_list	*list;
	t_list	*node;
	long	index;

	printf("Dime cuántos elementos quieres:");
	scanf("%d", &num_elements);
	list = ft_lstnew((void *)(long)0);
	index = 1;
	while (index <= num_elements)
	{
		node = ft_lstnew((void *)index);
		ft_lstadd_back(&list, node);
		index++;
	}
	ft_lstiter(list, test_function);
}
*/
