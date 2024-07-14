unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int mult;

	if (a == 0 || b == 0)
		return (0);
	mult = 1;
	while((a * mult) % b != 0)
		mult++;
	return (a*mult);
}
