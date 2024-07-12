/*Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
*/
#include <stddef.h>
#include "ft_list.h"

int	ft_list_size (t_list *begin_list)
{
	int len;

	len = 0;
	while (begin_list != NULL)
	{
		len++;
		begin_list = begin_list->next;
	}
	return (len);
}
/*para probar la funcion
#include <stdio.h>
int main(void)
{
	t_list node_1;
	t_list node_2;

	node_1.next = &node_2;
	node_2.next = NULL;
	printf("%d\n", ft_list_size(&node_1));
	printf("%d\n", ft_list_size(&node_2));
	printf("%d\n", ft_list_size(NULL));
}*/
