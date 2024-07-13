/*Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.*/

#include <stdlib.h>
int	*ft_rrange(int	start,int end)
{
	int	num_numbers;
	int	*numbers;
	int	i;

	if (end > start)
	{
		num_numbers = (end - start ) + 1;
		numbers = (int*) malloc (num_numbers * sizeof(int));
		i = 0;
		while (i < num_numbers)
		{
			numbers[i] = end;
			i++;
			end--;
		}
	}

	else 
	{
		num_numbers = (start - end )+ 1;
		numbers = (int*) malloc (num_numbers * sizeof(int));
		i = 0;
		while (i < num_numbers)
		{
			numbers[i] = end;
			i++;
			end++;
		}
	}
	return (numbers);
}

#include <stdio.h>
int	main(void)
{
	int	i;
	int	*result;
	
	i = 0;
	result = ft_rrange (1, -3);
	while (i < 5)
	{
		printf("%d\n", result [i]);
		i++;	
	}
}
