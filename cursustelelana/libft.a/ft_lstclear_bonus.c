//#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <string.h>

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
/*
static void	ft_free_itoa(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list;
	t_list	*node;

	list = ft_lstnew(ft_itoa(0));
	node = ft_lstnew(ft_itoa(1));
	list->next = node;
	printf("Antes del clear: %ld\n", (long)list);
	ft_lstclear(&list, ft_free_itoa);
	printf("Después del clear: %ld\n", (long)list);
	return (0);
}*/
