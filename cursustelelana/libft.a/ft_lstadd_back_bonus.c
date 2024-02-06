//#include <stdio.h>
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
/*
int	main(void)
{
	t_list *node;
	t_list *node2;
	t_list *node3;
	t_list *node4;
	
	node = ft_lstnew(1); 
	node2 = ft_lstnew (2);
	node3 = ft_lstnew(3);
	node4 = ft_lstnew (4);

	ft_lstadd_back(&node, node2);
	printf("%d\n", (node->next)->content); 
	ft_lstadd_back(&node, node3);
	printf("%d\n", ((node->next)->next)->content);
	ft_lstadd_back(&node, node4);
	printf("%d\n",((node->next)->next)->next -> content);
	return (0);
}*/
