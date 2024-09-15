/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:56:17 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/01 14:56:30 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*new_list;
	t_list	*to_remove;
	int	result;

	new_list = *begin_list;
	if(new_list == NULL)
		return;
	while(new_list != NULL && (*cmp)(data_ref, new_list->data) == 0 )
	{
		to_remove = new_list;
		new_list = new_list->next;
		*begin_list = new_list;
		free (to_remove);
	}
	if(new_list == NULL)
		return;
	while(new_list->next != NULL)
	{
		result = (*cmp)(data_ref, new_list->next->data);
		if(result == 0)
		{
			to_remove = new_list->next;
			new_list->next = new_list->next->next;
			free (to_remove);
		}
		else
			new_list = new_list->next;
	}
}

