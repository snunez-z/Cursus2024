#include <string.h>
#include <stdio.h>
#include <stddef.h>

int main (int argc, char **argv)
{

	size_t	result;

	result = strspn(argv[1], argv[2]);

	printf("Result :%zu\n", result);
	return (0);
}
