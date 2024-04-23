
/*Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$>*/

#include <unistd.h>

void putnbr (int num)
{
	char	numbers [10] = "0123456789";

	if (num > 0)
	{
		putnbr (num / 10);
		write (1,&numbers[num % 10], 1);
	}
}	

int	main (void)
{
	int num;

	num = 1;
	while (num <= 100)
	{
		if (num % 15 == 0)
			write (1,"fizzbuzz", 8);
		else if (num % 3 == 0)
			write (1,"fizz", 4);
		else if (num % 5 == 0)
			write (1,"buzz",4);
		else
			putnbr(num);
	num++;
	write (1, "\n", 1);
	}
}
