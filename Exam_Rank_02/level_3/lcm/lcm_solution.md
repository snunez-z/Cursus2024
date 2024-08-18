
# Commeted solution

1. lowest common multiple
    Maths solution based on prime numbers

    12 | 2      15 | 3
    6  | 2       5 | 5
    3  | 3       1 | 1
    1  | 1 

 2. Simple solution by brute force.

    We pick one of the numbers (example a) and multiply it, starting from one till we find a number that is divisible between b.
 a = 12 b = 15
    12 * 1 =  12 module % of 15 == 12 ( 12 / 15 = 0 modulus 12)
    12 * 2 =  24 module % of 15 ==  9 ( 24 / 15 = 1 modulus  9)
    12 * 3 =  36 module % of 15 ==  6 ( 36 / 15 = 2 modulus  6)
    12 * 4 =  48 module % of 15 ==  3 ( 48 / 15 = 3 modulus  3)
    12 * 5 =  60 module % of 15 == 0  ( 60 / 15 = 4 modulus 0)
 Now we know that 60 is the LCM.

 unsigned int lcm(unsigned int a, unsigned int b)
{
	unsigned int mult;

	mult = 1;
	while((a * mult) % b != 0)
		mult++;
	return (a*mult);
}

