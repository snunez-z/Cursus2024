#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#include "move_count.h"

static void print_list(t_stack_list *list)
{
	t_stack_list 	*aux;

	aux = list;
	while (aux != NULL)
	{
		printf("%ld ", aux->numbers);
		aux = aux->next;
	}
	printf("\n");
}

static int is_num_repeated(t_stack_list *a, int num)
{
	while(a != NULL)
	{
		if( a->numbers == num)
			return(1);
		a = a->next;
	}
	return (0);
}

int	main (int argc, char	**argv)
{
	int				i;
	long			num;
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
			if(is_num_repeated(a, num)!= 0)
			{
				list_destroy(a);
				list_destroy(b);
				printf("Error\n");
				return(-1);
			}
			list_append_front(&a, num);
			i++;
		}
		printf("Antes de hacer nada: ");
		print_list(a);
        
		enumerate_index_nodes(a);
		k_sort1(&a, &b);
		k_sort2(&a, &b);
		printf("\n");
		printf("Después del sort: ");
		print_list(a);
		print_list(b);
	}
	printf ("\n");
	printf("Moves = %d\n", move_count());
	list_destroy(a);
	list_destroy(b);
	return (0);
}