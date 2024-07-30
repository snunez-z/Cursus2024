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

void ft_putnbr(int num)
{
	char digit;

	if (num > 9)
		ft_putnbr(num / 10);
	digit = (num % 10) + '0';
	write(1, &digit, 1);
}

void multiplication(int num)
{
	int multiplicando;

	multiplicando = 1;
	while (multiplicando < 10)
	{
		ft_putnbr(multiplicando);
		write(1, " x ", 3);
		ft_putnbr(num);
		write(1, " = ", 3);
		ft_putnbr(multiplicando * num);
		write(1, "\n", 1);
		multiplicando++;
	}
}

#include <stdio.h>
int	main (int argc, char **argv)
{
	int	num;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (-1);
	}

	num = ft_atoi (argv[1]);
	multiplication (num);
	return (0);
}


