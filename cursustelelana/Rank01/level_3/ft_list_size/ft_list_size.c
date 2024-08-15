/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:55:50 by snunez-z          #+#    #+#             */
/*   Updated: 2024/08/15 11:47:23 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_list.h"

int	ft_list_size (t_list *begin_list)
{
	int len;

	len = 0;
	while (begin_list != NULL)
	{
		len++;
		begin_list = begin_list->next;
	}
	return (len);
}
/*para probar la funcion
#include <stdio.h>
int main(void)
{
	t_list node_1;
	t_list node_2;

	node_1.next = &node_2;
	node_2.next = NULL;
	printf("%d\n", ft_list_size(&node_1));
	printf("%d\n", ft_list_size(&node_2));
	printf("%d\n", ft_list_size(NULL));
}*/
