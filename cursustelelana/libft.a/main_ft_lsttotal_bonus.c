#include <stdio.h>
#include "libft.h"

int	main(void)
{
	t_list	*lst;
	int result;
	t_list *test;

	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew("SUSANA"));
	printf("%s %p\n",(char *)lst->content, lst->next);
	ft_lstadd_front(&lst, ft_lstnew("MARIA"));
	printf("%s %p\n", (char *)lst->next->content, lst->next);
	printf("%s\n",(char *)lst->content);
	ft_lstadd_back(&lst, ft_lstnew("JUANA"));
	printf("%p %s\n", lst->next, (char *)lst->next->content);
	printf("%s\n", (char *)ft_lstlast(lst)->content);
	result = ft_lstsize(lst);
	printf("%d", result);
	printf ("%s\n", (char*)(ft_lstlast(lst)->content));
	test = ft_lstnew("ALFONSA");
	ft_lstdelone (test,NULL);
	ft_lstclear (&lst, NULL);
	printf("%d\n", ft_lstsize(lst));	
}
