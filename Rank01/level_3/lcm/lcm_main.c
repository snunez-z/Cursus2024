#include <stdio.h>

unsigned int lcm(unsigned int a, unsigned int b);

int main(void)
{
	printf("lcm(12,15)=%d\n", lcm(12, 15));
	printf("lcm(2,2)=%d\n", lcm(2, 2));
	printf("lcm(10,100)=%d\n", lcm(10, 100));
	printf("lcm(0,0)=%d\n", lcm(0, 0));
	printf("lcm(11,50)=%d\n", lcm(11, 50));
	return (0);
}
