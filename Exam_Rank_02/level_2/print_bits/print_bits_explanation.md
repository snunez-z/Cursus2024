## Commented Solution

1. Every byte content 8 bits.
2. We use logical operation AND to encode the number.
3. If the result to pass the mask over the bit is zero, the bit is 0, so write 0.
4. If the result to pass the mask over the bit is diferent than 0, the bit is 1, so write 1.
5. You advance to the next position and divide the mask by 2 to move the mask from the left to the right.

