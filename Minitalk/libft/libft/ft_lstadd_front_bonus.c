/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:01:57 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 18:25:10 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "../libft.h"

void	ft_lstadd_front(t_list	**first_node, t_list	*new_node)
{
	if (*first_node == NULL)
		*first_node = new_node;
	else
	{
		new_node->next = *first_node;
		*first_node = new_node;
	}
}
/*
int	main(void)
{
	t_list	*first_node;
	t_list	*new_node;
	int		index;
	char	*copy;

	first_node = ft_lstnew((void *)((long)1));
	index = 2;
	while (index < 10)
	{
		new_node = ft_lstnew((void *)((long)index));
		ft_lstadd_front(&first_node, new_node);
		index++;
	}
	new_node = ft_lstnew("hola Sushi");
	ft_lstadd_front(&first_node, new_node);
	printf("%s\n", (char *)first_node->content);
	printf("%ld\n", (long)first_node->next->content);
	printf("%ld\n", (long)first_node->next->next->content);
	printf("%ld\n", (long)first_node->next->next->next->content);
}*/
