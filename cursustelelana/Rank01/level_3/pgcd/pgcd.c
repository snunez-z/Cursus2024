#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int a;
	int b;
	int cd;

	if (argc < 3 || atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0)
	{
		printf("\n");
		return (-1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	
	if (a < b)
		cd = a;
	else
		cd = b;
	while (cd > 1)
	{
		if ((a % cd) == 0 && (b % cd) == 0)
		{
			printf("%d\n", cd);
			return (0);
		}
		cd--;
	}

	printf("1\n");
	return (0);
}
