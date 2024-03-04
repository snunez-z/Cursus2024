/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 07:59:54 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/19 18:31:45 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
