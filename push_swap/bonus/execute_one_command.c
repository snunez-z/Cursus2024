#include "libft.h"
#include "push_swap.h"

static int	execute_one_rotate(char *comd, t_stack_list **a, t_stack_list **b)
{
	if (ft_strncmp(comd, "ra", 3) == 0)
	{
		ra(a, 0);
		return (1);
	}
	else if (ft_strncmp (comd, "rb", 3) == 0)
	{
		rb(b, 0);
		return (1);
	}
	else if (ft_strncmp (comd, "rr", 3) == 0)
	{
		rr(a, b, 0);
		return (1);
	}
	return (0);
}

static int	execute_one_reverse_rotate(char *comd, t_stack_list **a, t_stack_list **b)
{
	if (ft_strncmp (comd, "rra", 4) == 0)
	{
		rra(a, 0);
		return (1);
	}
	else if (ft_strncmp (comd, "rrb", 4) == 0)
	{
		rrb(b, 0);
		return (1);
	}
	else if (ft_strncmp (comd, "rrr", 4) == 0)
	{
		rrr (a, b, 0);
		return (1);
	}
	return (0);
}

static int	execute_one_swap(char *comd, t_stack_list **a, t_stack_list **b)
{
	if (ft_strncmp (comd, "sa", 3) == 0)
	{
		sa(a, 0);
		return (1);
	}
	else if (ft_strncmp (comd, "sb", 3) == 0)
	{
		sb(b, 0);
		return (1);
	}
	else if (ft_strncmp (comd, "ss", 3) == 0)
	{
		ss(a, b, 0);
		return (1);
	}
	return (0);
}

static int	execute_one_push(char *comd, t_stack_list **a, t_stack_list **b)
{
	if (ft_strncmp (comd, "pa", 3) == 0)
	{
		pa(a, b, 0);
		return (1);
	}
	else if (ft_strncmp (comd, "pb", 3) == 0)
	{
		pb(a, b, 0);
		return (1);
	}
	return (0);
}

int	execute_one_command(char *comd, t_stack_list **a, t_stack_list **b)
{
	if (execute_one_rotate(comd, a, b) == 1)
		return (1);
	if (execute_one_reverse_rotate(comd, a, b) == 1)
		return (1);
	if (execute_one_swap(comd, a, b) == 1)
		return (1);
	if (execute_one_push(comd, a, b) == 1)
		return (1);
	return (0);
}
