/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 07:54:01 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/08 07:54:06 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
/*
int	main(void)
{
	int		len;
	t_list	*node;
	t_list	*node2;

	node = ft_lstnew(1);
	len = ft_lstsize (node);
	printf("%d\n", len);
	node2 = ft_lstnew(10);
	len = ft_lstsize (node2);
	printf("%d\n", len);
	ft_lstadd_front(node, node2);
	len = ft_lstsize (node);
	printf("%d\n", len);
	len = ft_lstsize (node2);
	printf("%d\n", len);
	len = ft_lstsize(NULL);
	printf("%d\n", len);
	return (0);
}*/
