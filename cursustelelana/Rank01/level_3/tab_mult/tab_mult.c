/*Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>*/

#include <unistd.h>
static int	ft_isdigit (char  digit)
{
	if (digit >= '0' && digit <= '9')
		return (1);
	else
		return (0);
}

int 	ft_atoi(const char	*num)
{
	int	value;
	int	i;

	if (num[0] == '-')
		i = 1;
	else
		i = 0;
	value = 0;
	while (ft_isdigit(num[i]) != '\0')
	{
		value = (value * 10) + (num[i] - '0');
		i++;
	}
	
	if (num[0] == '-')
		value = value *-1;
	return (value);
}


// putnbr y llamarse con al multiplicacion y pintar.
//
}	

/*int	main(int argc, char **argv)
{
	if (argc == 2)
	{


	}
	write (1, "\n", 1);
	return (0);
}
*/


#include <stdio.h>
int	main (void)
{
	int	num;
	int	total;

	num = ft_atoi ("-16");
        total = multiplication (num);
        return (0);
}

