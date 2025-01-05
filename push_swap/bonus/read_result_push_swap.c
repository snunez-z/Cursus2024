 
#include <unistd.h>
#include <stddef.h>
#include "ft_printf.h"
#include "push_swap.h"
#include "libft.h"

static int	read_line(int fd, char *buffer, size_t bytes_max)
{
	char	ch;
	int		read_result;
	size_t	index;

	index = 0;
	read_result = read(fd, &ch, 1);
	while (read_result == 1 && index < bytes_max && ch != '\n')
	{
		buffer[index] = ch;
		index++;
		read_result = read (fd, &ch, 1);
	}
	buffer [index] = '\0';
	if (read_result < 0 || index >= bytes_max)
		return (-1);
	return (index);
}

static void	execute_one_command(char *comd, t_stack_list **a, t_stack_list **b)
{
	if (ft_strncmp(comd, "ra", 3) == 0)
		ra(a, 0);
	else if (ft_strncmp (comd, "rb", 3) == 0)
		rb(b, 0);
	else if (ft_strncmp (comd, "rr", 3) == 0)
		rr(a, b, 0);
	else if (ft_strncmp (comd, "rra", 4) == 0)
		rra(a, 0);
	else if (ft_strncmp (comd, "rrb", 4) == 0)
		rrb(b, 0);
	else if (ft_strncmp (comd, "rrr", 4) == 0)
		rrr (a, b, 0);
	else if (ft_strncmp (comd, "sa", 3) == 0)
		sa(*a, 0);
	else if (ft_strncmp (comd, "sb", 3) == 0)
		sb(*b, 0);
	else if (ft_strncmp (comd, "ss", 3) == 0)
		ss(*a, *b, 0);
	else if (ft_strncmp (comd, "pa", 3) == 0)
		pa(a, b, 0);
	else if (ft_strncmp (comd, "pb", 3) == 0)
		pb(a, b, 0);
}

int	read_result_push_swap(t_stack_list **a, t_stack_list **b)
{
	int		read_result;
	char	buffer[10];

	read_result = read_line (0, buffer, 9);
	while (read_result > 0)
	{
		execute_one_command(buffer, a, b);
		read_result = read_line (0, buffer, 9);
	}
	return (read_result);
}
