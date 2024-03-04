/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 07:56:12 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 18:30:24 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*each_node;
	t_list	*aux;

	each_node = *lst;
	while (each_node != NULL)
	{
		aux = each_node->next;
		ft_lstdelone(each_node, del);
		each_node = aux;
	}
	*lst = NULL;
}
