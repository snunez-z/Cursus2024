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

#include "libft.h"

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
