#include <unistd.h>

int	putnbr (int	num)
{
	char digit;

	digit = (num % 10) + '0';
	if (num > 10 )
		putnbr (num / 10);
	write (1 , &digit, 1);
}

int main(int argc, char **argv)
{
	putnbr(argc-1);
}	

