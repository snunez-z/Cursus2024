

#include <unistd.h>
#include "libft.h"
#include "push_swap.h"

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

static void free_split(char **split)
{
	int index;

	index = 0;
	while(split[index] != NULL)
	{
		free(split[index]);
		index++;
	}
	free(split);
}

int parse_argv(char *argv, t_stack_list **stack)
{
	char **split;
	int index;
	long num;
	int	atoi_error;

	split = ft_split(argv, ' ');
	if (split == NULL)
		return (0);

	index = 0;
	while (split[index] != NULL)
	{
		num = su_atoi(split[index], &atoi_error);
		if (atoi_error == 1 || is_num_repeated (*stack, num) != 0)
			return (0);

		if (list_append_front(stack, num) == NULL)
		{
			free_split(split);
			// el list_destroy lo hace el "main", no tenemos que hacerlo nosotros aqui
			return (0);
		}
		index++;
	}

	free_split(split);
	return (1);
}
