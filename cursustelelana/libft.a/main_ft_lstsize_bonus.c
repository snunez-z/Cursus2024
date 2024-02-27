#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_list	*lst;

	lst = NULL;
	lst = ft_lstnew("SUSANA");
	ft_lstadd_front(&lst, ft_lstnew("MARIA"));
	printf("%p = %s %s\n", lst->next, (char *)lst->content,(char *) lst->next->content);
	ft_lstadd_back(&lst, ft_lstnew("JUANA"));
	printf("%p = %s %s\n", lst->next, (char *)lst->content, (char *)lst->next->next->content);
	printf("%d\n", ft_lstsize(lst));
	ft_lstclear(&lst,NULL);
}
