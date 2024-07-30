#include <stdio.h>

int	main(void)
{
	int	numbers [] = {4,8,2,6,3,9, 8,120,6,80};
	int	i;

	sort_int_tab (numbers, 10);
	i = 0;
	while (i < 10)
	{
		printf ("%d ", numbers[i]);
		i++;
	}
	return (0);
}
