## Commented Solution

1. We go through the string to the end, skipping all the characters to get to the end.
2. Loop with the condition that index is zero or smaller than zero ( First position of the string).
3. We place ourselves in the position before the '\0' by subtracting one from the index.
4. Declare a variable end (which it represents the end of a word) .
5. While the char is diferent to space and index is smaller/equal than zero iter index from the right to the left.
6. When we reach an space . start value is the same as i plus 1 to jump the space.
7. Now we can write de word from start to the end .
   - We should substract end to start and add 1 to include start.
   . Example = "uno dos"
     	i = 3
	start = 4
	end = 6
    end - start = 2 and we want to write three "the word dos", so we should add 1 more.
    write (1, &str[start], end - start + 1.
8. we are going to need and space between words in all words except the first one.
   The frst word will be at the end of teh string, so the space after it is not necesary.
   Behind the last word is '\0'.
10. When we reach the first word starts value is zero, so we use this fact to put it as a condition.
11. If start is greater than zero we write an space.
    So, only if it is the first word the programme doesn't write an space.
12. We finishes writting a break line \n.
