## Commented Solution

1. We have to change the 4 bits on the right to the left.
   Since it is not a matter of changing the order of the 8 bits, but rather moving 4 from the left to the right and vice versa, we cannot do it in just 1 step. It has to be done in 2.
2. Octect is the original argument but we need a "result" variable to save the result of the changes we are going to make.
3. In the first block we need to detect the bits that are at 1, for that we use the logical AND operation and a mask initialized at 128.
4. For the first block of 4 the mask_and starts at 128 up to 16. It will detect if the bit is 1 and in result it will put the result of the logical operation OR. Since we initialize result to zero, the OR operation allows us that whenever a bit 1 is found, the result is 1. It is a way of passing the 1s from one side to the other.
5. They will then move to the next bit by dividing by two. Both the mask_and and the mask_or,.
6. For the second block we do the same but in the opposite direction.
We start the mask_anden at 8 and the mask_or at 128 and so we go from position 8 to 128 for each bit.
7. Return result.
