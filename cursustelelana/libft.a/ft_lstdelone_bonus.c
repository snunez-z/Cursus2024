/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 07:56:30 by snunez-z          #+#    #+#             */
/*   Updated: 2024/02/12 07:40:52 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <string.h>

/*
static void ft_free_itoa(void *content)
{
	free(content);
}
*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del != NULL)
		(*del)(lst->content);
	free(lst);
}

/*
int main(void)
{
	t_list *list;

	list = ft_lstnew(ft_itoa(0));
	ft_lstdelone(list, ft_free_itoa);

	list = ft_lstnew("hola");
	ft_lstdelone(list, NULL);

	return (0);
}
*/
