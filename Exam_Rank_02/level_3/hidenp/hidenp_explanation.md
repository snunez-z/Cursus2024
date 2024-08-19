## Commented Solution

Since we have to search for the first string in the second and in the order of the first, we need to go through the first and for each character look for it in the second.
And we need two index , one i to go through the first string and another j, to go through the second and look for each character not from the beginning but from the position of j.
1. Corner case. If we don't received the three elements we need or teh first string is empty, write a break line \n and exit.
2. Both index starts at zero.
3. Loop with the condition that the first string doen't reach the end of it.
4. Inside this loop, for every character we need another loop to transverse the second string.
    - condition if we dont find the character and it is not teh end, we go on searching, itering to next position.
    - If the second string reach the end, this means that teh character searchedfor has not been found. 
    - So write 0 followed by breakline \n.Exit.
5. if not, iter the index of the first string to search the next character. 
   Iter the index of the second string to make sure that the next searching start from the next position of the last position.
Example : HHHHHH H -> if index j dont search from teh next position, teh programe is going to return 1, because it always find the character H, but is is start searching from the j + 1, next position, it finds the \0 and return 0.
6. If it hasn't exited before, it means that it has found all the characters from the first string in the second, so it can type the newline \n and return 1. 
