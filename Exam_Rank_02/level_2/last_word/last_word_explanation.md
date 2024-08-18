## Commented Solution

1. First we go through the entire string iterating until we reach '\0'.
2. Iterate the index one time to place us in the position before '\0'.
3. While the character in the string is space/tab the index is bigger or equal to cero, iterate i.
   To find the first letter of the last word.
4. While the character is diferent to space/tab, iterate from the right to the left.
5. When space/tab is found you advance the index one time to place it in the first position of the word.
6. While it is not the end of teh string and it is diferent to space/tab and diferent to space.
   So you can write the letter and iterate to the folowing letter till the end.
7. Finish writting a \n.

