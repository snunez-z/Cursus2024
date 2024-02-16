/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 07:57:03 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/12 11:10:53 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstlast(t_list	*lst)
{
	t_list	*last;

	last = NULL;
	while (lst != NULL)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}
/*
int	main(void)
{
	t_list	*node;
	t_list *node2;
	t_list *node3;
	t_list *last;

	last = ft_lstlast(NULL);
	printf("%ld\n", (long)last);
	
	node = ft_lstnew (1);
	last = ft_lstlast(node);
	printf("%d\n", last->content);

	node2 = ft_lstnew (2);
	ft_lstadd_front(node, node2);
	last = ft_lstlast(node2);
	printf("%d\n", last->content);
	last = ft_lstlast(node);
	printf("%d\n", last->content);

	node3 = ft_lstnew (3);
	ft_lstadd_front(node2, node3);
	last = ft_lstlast(node3);
	printf("%d\n", last->content);
	last = ft_lstlast(node2);
	printf("%d\n", last->content);
	last = ft_lstlast(node);
	printf("%d\n", last->content);
	return (0);
}*/
