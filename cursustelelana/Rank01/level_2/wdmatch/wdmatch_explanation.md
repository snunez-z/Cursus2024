## Commented Solution

We are asked to check if the first string is inside the second and in the same order as the first. In that case we can write it followed by a newline, otherwise we simply return a newline.
1. We have to go through the first string and for each character check if it is in the second string.
2. For this we create the "is_possible" function.
   - We go through the first string and for each character we go through the second string.
   - For each character in the first string we have to look if it is in the second string but not always from the beginning. 
   - We need an index variable to go through the first string and also an index variable for the second so we know where to look for that character.
   - While the character is not the end of the string and the character is diferent to the character of the first string.
     iter the index;
   - If the second string has reached the end of the string it means that it is not possible, that I have not found all the characters of the first.
   - Therefore return 0 and exit.
   - If the character are the same, iter the index j to place ourselves in the next position. 
   - This way, the next time we search for a character, it will do so from that position.
   - Iter the index i to go for the next character of the first string;
3. At the end of the loop, return 1 to indicate that it is possible.
4. If when you call the function "is_psoble" teh result is 1, we will write the first string.
5. To do it we need to know the size of the first string, number of bytes.
   So, we create a a function "ft_strlen" that return teh number of bytes of one string received as an argument.

 
