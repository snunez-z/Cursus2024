#include <unistd.h>
int 	ft_atoi(const char	*num)
{
	int	value;
	int	i;

	i = 0;
	value = 0;
	while (num [i] != 0)
	{
		value = (value * 10) + (num[i] - '0');
		i++;
	}
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


