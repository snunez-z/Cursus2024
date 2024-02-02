/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 07:45:48 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/02 07:48:25 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstadd_front(t_list	*first_node, t_list	*next_node)
{
	first_node->next = next_node;
	return (first_node);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*list;

	node1 = ft_lstnew (13);
	node2 = ft_lstnew(14);
	list = ft_lstadd_front(node1, node2);
	printf("% d, %d\n", list->content, list->next->content);
	printf("%ld\n", (long)list);
	printf("%ld\n", (long)list->next);
	printf("%ld\n", (long)list->next->next);
}
