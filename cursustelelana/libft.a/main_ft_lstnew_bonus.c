#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	t_list	*new_node;
	
	new_node = ft_lstnew("Susana");
	printf("%s %s", new_node->content, (char *)new_node->next);
}
