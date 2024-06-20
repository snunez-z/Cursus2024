#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("usage %s <num>\n", argv[0]);
		return 1;
	}
	int num = atoi(argv[1]);
	if (num < 0 || num > 255)
	{
		printf("Tío, pásame algo entre 0 y 255\n");
		return 1;
	}

	int veces = 0;
	int mask = 128;
	while(veces < 8)
	{
		int resultado = num & mask;
		if (resultado == 0)
			printf("0");
		else
			printf("1");
		mask = mask / 2;
		veces++;
	}
	printf("\n");

	return 0;
}
