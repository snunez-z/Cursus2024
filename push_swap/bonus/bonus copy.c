 #include <unistd.h>
 #include <stddef.h>
 #include "ft_printf.h"
 #include "push_swap.h"
 #include "libft.h"

int	main (int argc, char	**argv)
{
	int				i;
    char    buffer[10];
    int read_result;
	t_stack_list	*a;
	t_stack_list	*b;

    if(argc > 1)
	{
		i = 1;
		a = NULL;
		b = NULL;
		while (i < argc)
		{
			if (!parse_argv(argv[i], &a))
			{
				list_destroy (a);
				list_destroy (b);
				ft_printf("Error\n");
				return (-1);
			}
			i++;
		}
        read_result = read_line (0, buffer, 9);
        while (read_result > 0)
        {
            if (ft_strncmp(buffer, "ra", 3) == 0)
                ra(&a, 0);
            else if( ft_strncmp (buffer, "rb", 3) == 0)
                rb(&b, 0);
            else if( ft_strncmp (buffer, "rr", 3) == 0)
                rr(&a, &b, 0);
            else if( ft_strncmp (buffer, "rra", 4) == 0)
                rra(&a, 0);
            else if( ft_strncmp (buffer, "rrb", 4) == 0)
                rrb(&b, 0);
            else if( ft_strncmp (buffer, "rrr", 4) == 0)
                rrr(&a, &b, 0);
            else if( ft_strncmp (buffer, "sa", 3) == 0)
                sa(a, 0);    
            else if( ft_strncmp (buffer, "sb", 3) == 0)
                sb(b, 0);
            else if( ft_strncmp (buffer, "ss", 3) == 0)
                ss(a, b, 0); 
            else if( ft_strncmp (buffer, "pa", 3) == 0)
                pa(&a, &b, 0);
            else if ( ft_strncmp (buffer, "pb", 3) == 0)
                pb(&a, &b, 0);  
           read_result = read_line (0, buffer, 9);
        }

        if (read_result < 0)
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




