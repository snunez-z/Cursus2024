#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

int	main (int argc, char	**argv)
{
	int				i;
	long			num;
	t_stack_list 	*aux;
	t_stack_list	*num_list;	
	
	if (argc > 2 )
	{
		i = 1;
		num_list = NULL;
		while (i < argc)
		{
			num = su_atoi(argv[i]);
			list_append(&num_list, num);
			i++;
		}
		aux = num_list;
		while (aux != NULL)
		{
			printf("%ld ", aux->numbers);
			aux = aux->next;
		}
	}
	write(1,"\n", 1);
	list_destroy(num_list);
	return (0);
}
