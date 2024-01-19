#include <unistd.h>
#include <stdio.h>

void	ft_atoi(int a)
{
	int	d1;
	char	b;

	d1 = a / 10;
	b = d1 + '0';
	write (1, &b, 1);

	d1 = a % 10;
	b = d1 + '0';
	write (1, &b, 1);
}

void	ft_print_comb2(void)
{
	int numi;
	int numd;
	
	numi = 0;
	while (numi <= 99)
	{
		numd = numi + 1;
		while (	numd <=99)
		{	
			ft_atoi(numi);
			write(1, " ", 1);
			ft_atoi(numd);
			write(1, ", ", 2);
			numd++;
		}	
		numi++;
	}
}

int	main(void)
{	
	ft_print_comb2();
	return (0);
}
