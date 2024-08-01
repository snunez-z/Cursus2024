# Commented Solution

1. We create a function  " is_lower" that tells us if the character in a position is lowercase or not.
2. First check that we do not have an space/tab in the first position of the string.
   Iterate while you find an space or tab to reach one letter.
3. We go through the string with a loop with the condition that it has not reached the end.
4. If what is inside the string position is different from a underscore, we could verify more conditions.
5. If in the previous position there is a underscore_ and it is lowercase, we convert it to uppercase and write it.
6. Iterate the index to advance to the next byte.
7. when it is finished write line break \n.
   
