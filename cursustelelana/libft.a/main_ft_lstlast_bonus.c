#include <stdio.h>
#include "libft.h"

int main(void)
{
	t_list	*lst;

	lst = NULL;
	lst = ft_lstnew("SUSANA");
	printf("%p = %s\n", lst->next, (char *) lst->content);
	ft_lstadd_front(&lst, ft_lstnew("MARIA"));
	printf("%p %s\n", lst->next, (char *)lst->content);
	printf("%s\n", (char *)lst->next->content);
	printf("%s\n", (char*)ft_lstlast(lst)->content);
	ft_lstclear(&lst, NULL);
}	 

