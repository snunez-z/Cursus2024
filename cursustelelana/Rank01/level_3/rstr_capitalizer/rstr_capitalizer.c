int	is_space (char ch)
{
	if (ch == ' ' || ch == '\t')
		return (1);
	else
		return (0);
}

#include <unistd.h>

int	main (int argc, char **argv)
{
	int i;
	int j;

	if (argc == 1)
	{
		write (1, "\n", 1);
		return (-1);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] >= 'a' && argv[i][j] <= 'z') && (is_space (argv [i][j + 1]) == 1 || argv[i][j + 1] == '\0'))
				argv[i][j] = argv[i][j] - ( 'a' - 'A');
			else if ((argv[i][j] >= 'A' && argv[i][j] <= 'Z') && (is_space (argv[i][j + 1]) == 0 && argv[i][j + 1] != '\0'))
				argv[i][j] = argv[i][j] - ('A' - 'a');
			write (1, &argv[i][j], 1);
			j++;		
		}
		write (1, "\n", 1);
		i++;
	}	
	return (0);
}
