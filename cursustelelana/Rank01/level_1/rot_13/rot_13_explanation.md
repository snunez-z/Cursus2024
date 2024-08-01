# Commented Solution

1. Run the string till reach the '\0'.
2. For each character we should check if the character is between a and z in lower or in upper case.
3. Rest the value of the character to the value of 'a' or 'A' and the result % 26 to narrow down and add the value of 'a' 'A'4. Into alphabeth between 0 and 25 there are 26 characters, therefore if it goes beyond 26 it starts again. 
   For that we use module 26, to limit it and so that when it is passed it starts again from the beginning.
5. Write the character and iter the index.
6. Finish with \n.
