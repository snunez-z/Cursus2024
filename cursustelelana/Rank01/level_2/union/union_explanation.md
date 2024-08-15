## Commented Solution

As they ask us to put all the letters that are in both ,one string and the other, but in the order of the first...
1. We need to loop through the first string to see if there are any repeated characters.
2. For his, we create a function "is_repetaed" that detect if teh character is repeated or not.
3. Only we will write the character if it is not repeated.
4. We need to loop through the second string .
5. We introduce a condition for every charcater.
6. The condition will be that it is not repeated in the second string and also is not within the first string, that is, that it is a new character.
   Then write the character and iter the index.
7. To check if the character of the second string is in the first string we create a function "search_char" that seach a char into a string and return if it is or not it is in.
8. When we have exited the loop, we are finished and can write a \n.

