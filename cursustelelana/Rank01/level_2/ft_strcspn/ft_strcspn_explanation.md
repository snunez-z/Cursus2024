## Commented Solution

We should compare every position of the both strings and return the number of them there are before they find the first coincidence.
Examples: "Hola" "ola" return 1, because there is only one character "H" before the first coincidence "o" is founded.
1. We need to search every character of teh first srting into the second one, so one loop within a loop.
2. Declare and initialize an index for the first loop.
3. While the first string doen't reach the end of it.
4. Declare and initialize an index for the second string.
5. While teh second string doen't reach teh end of it.
   At the moment a coincidence appears, return teh value of position which means that this value corresponds to the number of characters 
   that exist before that coincidence.
6. if not iter the position of the second string.
7. When the traversal of the first position of the first string ends, we iterate to the second position of the first string. 
   We do this to compare the next position of the first string.
8. The loop finishes when the first string has reached the end so we return the position.
