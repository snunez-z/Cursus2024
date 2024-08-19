
## Commeted solution

The least common multiple is the smallest number that is divisible by both parameters.
We know that the LCM exists. Worst case the LCM is a*b
So what we do is take one of the two numbers (for example a)
and we multiply it first by 1, then 2, then by 3 and so on
until the result of the multiplication is a multiple of b (that is, the result of the multiplication % b is zero)
There is no need to ask if the result of the multiplication is
a multiple of a... because if I multiply a by anything, the
result is a multiple of

 1. Simple solution by brute force.

    We pick one of the numbers (example a) and multiply it, starting from one till we find a number that is divisible between b.
 a = 12 b = 15
    12 * 1 =  12 module % of 15 == 12 ( 12 / 15 = 0 modulus 12)
    12 * 2 =  24 module % of 15 ==  9 ( 24 / 15 = 1 modulus  9)
    12 * 3 =  36 module % of 15 ==  6 ( 36 / 15 = 2 modulus  6)
    12 * 4 =  48 module % of 15 ==  3 ( 48 / 15 = 3 modulus  3)
    12 * 5 =  60 module % of 15 == 0  ( 60 / 15 = 4 modulus 0)
 Now we know that 60 is the LCM.

- Note -> lowest common multiple -> DEscomposition of the numbers
  Maths solution based on prime numbers

    12 | 2      15 | 3
    6  | 2       5 | 5
    3  | 3       1 | 1
    1  | 1 

