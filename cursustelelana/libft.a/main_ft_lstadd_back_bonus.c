#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_list	*lst;
	t_list	*lst2;

	lst = ft_lstnew("SUSANA");
	ft_lstadd_front(&lst, ft_lstnew ("MARIA"));
	lst2 = ft_lstnew (" JUANA"); 
	ft_lstadd_back (&lst,lst2);
	printf("%p %s\n", lst->next, (char *)lst->next->content);
	printf("%p %s\n", lst2->next, (char *)lst2->content);
	ft_lstclear(&lst, NULL);
}
