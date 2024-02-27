#include <stdio.h>
#include "libft.h"

void	ft_printf(void	*s)
{
	printf("%s\n", (char *)(s));	
}

void	*ft_convert_toupper(void	*s)
{
	int	index;
	char *aux;
	char *copy;

	aux = (char *)s;
	copy = ft_strdup(aux);
	index = 0;
	while (copy[index] !='\0')
	{
		copy[index] = ft_toupper(aux[index]);
		index++;
	}
	return((void *)copy);		
}
int	main(void)
{
	t_list	*lst;
	t_list	*new_list;

	lst = NULL;
	lst = ft_lstnew("susana");
	ft_lstadd_front(&lst, ft_lstnew("maria"));
	ft_lstadd_back(&lst,ft_lstnew("juana"));
	new_list = ft_lstmap(lst, ft_convert_toupper, free);
	ft_lstiter (new_list, ft_printf);
}
