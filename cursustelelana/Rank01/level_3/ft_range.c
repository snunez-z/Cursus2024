/*Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.*/

int		*ft_range(int	start, int end)
{
	int	*numbers;
	int	num_numbers;
	int inc;

	if (start > end)
	{
		num_numbers = (end - start) + 1; 
		inc = 1;
	}
	else
	{
		// Esto es para el corner case de que start sea MAS PEQUENIO que end
		num_numbers = (start - end) + 1; 
		inc = -1;
	}
	numbers = (int *) malloc (num_numbers * sizeof(int));
	index = 0;
	while (index < num_numbers)
	{
		numbers[index] = start;
		index++;
		start = start + inc;
	}
	return (numbers);	
}
