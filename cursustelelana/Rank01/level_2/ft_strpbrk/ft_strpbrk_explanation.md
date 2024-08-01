# Commented Solution

The strpbrk() function returns a pointer to the byte in s that matches one of the bytes in s2. NULL if no such byte is found.
1. Declare and initialize to 0 an index.
2. We need to run the first s1 while it doesm't reach the '\0. 
   Loop where every character is searched in the whole s2.
3. Declare and initialize to 0 an index.
4. Loop to loop through the second string and if it finds a match, it returns the position it is in and exits. 
   If not found, iterates to the end of the string.
5. Iterate the index of teh first string.
6. If there is no coincidence, return NULL.

Null is a constant declared as a pointer to memory address zero, which cannot be used. It is necessary to define a value that is not valid
, zero was considered. That's why it is reserved for an invalid pointer. There are functions that return Null because they may fail or 
because I have not been able to do what I want to do, Null is used for this.
If functions that return a pointer usually use return null when they fail, what I do is return Null.
