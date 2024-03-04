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
