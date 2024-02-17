/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 07:59:54 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/12 10:47:14 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*iter;
	t_list	*new_list;
	t_list	*node;
	void	*new_content;

	iter = lst;
	new_list = NULL;
	while (iter != NULL)
	{
		new_content = (*f)(iter->content);
		node = ft_lstnew(new_content);
		if (node == NULL)
		{
			if (del != NULL)
				(*del)(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		iter = iter->next;
	}
	return (new_list);
}
/*
static void	*add_one(void	*content)
{
	long	num;:wq
	
	num = (long)content;
	return ((void *)(num * 10));
}

static void	print_value(void	*content)
{
	long	num;

	num = (long)content;
	printf("%ld ", num);
}

int	main(void)
{
	int		num_elements;
	t_list	*list;
	t_list	*new_list;
	t_list	*node;
	long	index;

	printf("Dime cuántos elementos quieres:");
	scanf("%d", &num_elements);
	list = ft_lstnew ((void *)(long)0);:w
	index = 1;
	while (index <= num_elements)
	{
		node = ft_lstnew((void *)index);
		ft_lstadd_back(&list, node);
		index++;
	}
	printf("Lista original: ");
	ft_lstiter(list, print_value);
	new_list = ft_lstmap (list, add_one, NULL);
	printf("\nLista creada con ft_lstmap: ");
	ft_lstiter(new_list, print_value);
	printf("\n");
}*/
