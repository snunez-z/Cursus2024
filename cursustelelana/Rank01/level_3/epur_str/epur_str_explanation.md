## Commented Solution

1. We create a function that checks if the character is a space or not "is_space"
2. Since there may be spaces at the beginning or other strange characters, we check them.
   If there are any, we skip them by iterating the index.
3. Loop to trasverse the string to the end.
   - Loop with the following condition :
     if it not an space and it is not the end of the string.
     write the char
     iter to the next itering the index.
   - Loop with the following condition :
     if it is an space and it is not the end of the string, jump by itering the index.
   - if we find a char and is not the end, we can write an space (the space requested).
4. Finally we should write a break line \n.

