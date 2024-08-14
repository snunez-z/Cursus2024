## Commented Solution


1. Every byte content 8 bits.
2. We use logical operation AND to encode the number.
3. If the result to pass the mask over the bit is cero, the bit is 0, so write 0.
4. If the result to pass the mask over the bit is 1, the bit is 1, so write 1.
5. You t position and divided the mask by 2 to move the mask from the left to the right.

