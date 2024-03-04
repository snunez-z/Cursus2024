/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 07:55:24 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/08 07:55:27 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list	**first_node, t_list *new_last_node)
{
	t_list	*last_node;

	if (*first_node == NULL)
		*first_node = new_last_node;
	else
	{
		last_node = ft_lstlast (*first_node);
		last_node->next = new_last_node;
	}
}
