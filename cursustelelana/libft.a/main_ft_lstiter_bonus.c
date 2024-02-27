#include <stdio.h>
#include "libft.h"

void	ft_print(void *s)
{
	printf("%s ", (char *) s);
}

void	*convert_toupper(void *s)
{
	int		index;
	char	*aux;
	char 	*copy;

	aux = (char *)s;
	copy = ft_strdup(aux);
	index = 0;
	while (aux[index] != '\0')
	{
		copy[index] = ft_toupper(aux[index]);
		index++;
	}
	return (copy);
}
int	main(void)
{
	t_list	*lst;
	t_list	*last;
	int	result;
	t_list *copy;

	lst = NULL;
	lst = ft_lstnew("susana");
	ft_lstiter( lst, ft_print);
	printf("\n");
	ft_lstadd_front(&lst,ft_lstnew("maria"));
	ft_lstiter( lst, ft_print);
	printf("\n");
	ft_lstadd_back(&lst, ft_lstnew("juana"));
	ft_lstiter(lst, ft_print);
	printf("\n");
	last = ft_lstlast(lst);
	printf("%s\n", (char *)last->content);
	result = ft_lstsize(lst);
	printf("%d\n", result);
	copy = ft_lstmap (lst, convert_toupper, free);
	ft_lstiter(lst,ft_print);
	printf("\n");
	ft_lstiter(copy,ft_print);

	ft_lstclear(&lst, NULL);
	ft_lstclear(&copy, free);
}
