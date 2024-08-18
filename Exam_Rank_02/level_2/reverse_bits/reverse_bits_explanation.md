## Commented Solution

We are going to return the byte resulting from the bit shift that is made.

1. We declare a variable byte and initialize to cero.This way we can have all the bits to cero.
   0 = 0000 0000 
   This way we only put the bits to 1 if it is necessesary. 
2. While index doesn't reach 8 .
3. If applying the logical AND operation the result is different from zero, that is, 1
   Byte value will be the result to aplly the logical OR logical operation .
4. Advance to another bit.
5. The encoding mask will advance by dividing by two
6. The decoding mask will advance by multiplying by 2 
7. Return the byte reslting with the bit shift that is made. 
