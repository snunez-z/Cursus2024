/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 07:51:21 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/02 07:53:18 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc (sizeof (t_list));
	if (new_node != NULL)
	{
		new_node->content = content;
		new_node->next = NULL;
	}
	return (new_node);
}

/*
int	main(void)
{
	int	num;
	t_list	*node;

	num = 13;
	node = ft_lstnew (num);
	printf("%d %ld", node->content, (long)node->next);
}
*/
