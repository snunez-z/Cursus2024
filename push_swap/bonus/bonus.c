
#include <unistd.h>
#include <stddef.h>
#include "ft_printf.h"
#include "push_swap.h"
#include "libft.h"

static int	checker_argv(int argc, char **argv, t_stack_list **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (parse_argv(argv[i], a) == 0)
		{
			list_destroy (*a);
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack_list	*a;
	t_stack_list	*b;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		if (!checker_argv(argc, argv, &a))
			return (-1);
		if (read_result_push_swap(&a, &b) < 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		if (is_sorted(a, 0) && list_size (b) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		list_destroy(a);
		list_destroy(b);
		return (0);
	}
}
