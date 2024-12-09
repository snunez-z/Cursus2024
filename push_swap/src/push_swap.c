#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "move_count.h"


int	main (int argc, char	**argv)
{
	int				i;
	long			num;
	t_stack_list 	*aux;
	t_stack_list	*a;
	t_stack_list	*b;

		
	if (argc > 2 )
	{
		i = 1;
		a = NULL;
		b = NULL;
		while (i < argc)
		{
			num = su_atoi(argv[i]);
			list_append_front(&a, num);
			i++;
		}
		sort_stacks(&a, &b);
		aux = a;
		while (aux != NULL)
		{
			printf("%ld ", aux->numbers);
			aux = aux->next;
		}
	}
	printf ("\n");
	printf("Moves = %d\n", move_count());
	list_destroy(a);
	list_destroy(b);
	return (0);
}
