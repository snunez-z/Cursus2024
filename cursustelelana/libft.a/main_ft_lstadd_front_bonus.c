#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_list	*lst;
	
	lst = ft_lstnew ("Susana");
	printf("%s %p\n", (char *) lst->content, lst->next);
	ft_lstadd_front(&lst, ft_lstnew("Maria"));
	printf("%s %p\n", (char *) lst->content, lst->next);
	ft_lstclear(&lst, NULL);
}
