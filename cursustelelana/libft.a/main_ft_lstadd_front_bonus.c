#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_list	*first_node;
	t_list	*new_node;

	first_node = ft_lstnew ("Susana");
	
	new_node = ft_lstnew ("Maria");
	printf("%s %ld\n", first_node->content,(long)first_node->next);
	ft_lstadd_front(&first_node, new_node);
	printf("%s, %s", first_node->content, new_node->content);
}
