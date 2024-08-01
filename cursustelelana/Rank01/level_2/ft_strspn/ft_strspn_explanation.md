# Commented Solution

This function receives two strings and return the numbers of bytes that there are in the first string that there are too in the second string in the same position.

1. Loop will go through the first string until it reaches the end and we will search within the second string if that character is there. 
   Therefore we have to go through the second string.
2. We declare a variable ocurrence to check if it is or no (true or false).
   We used it for the second loop, the loop to run the second string.
3. If we find an ocurrence, iterate the index j to check if there is more ocurrences.
   if not, assume that there is no ocurrences and exit returning the position index i.
4. Iterate index of the first string.
5. When it reaches the end of the first loop it has finished searching for matches from the first to the second and returns the position, 
   which tells us how many consecutive bytes they share. 
