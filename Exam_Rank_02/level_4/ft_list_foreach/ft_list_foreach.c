/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 07:27:35 by snunez-z          #+#    #+#             */
/*   Updated: 2024/09/16 07:27:48 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_list.h"
#include <stdlib.h>

void	ft_list_foreach (t_list *begin, void (*f) (void *))
{
	t_list	*list_ptr;

	list_ptr = begin;
	while(list_ptr != NULL)
	{
		(*f) (list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

