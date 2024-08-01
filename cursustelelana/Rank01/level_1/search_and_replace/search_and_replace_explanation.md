# Commented Solution

1. We first contemplate the three scenarios nedded to our program has not to exit after having written a \n.
   we need to check that the arguments are three and the second and third argument is only a letter, no more.
   so only if the position [1] of argv 2 & 3 is '\0', the position cero is a character.
2. We run the first string (argv [1]] till end of it.
3. For every position if the character in argv [1] is equal to the letter in argv [2] in the position [0]
   then we change it to the character of argv[3].
4. Write the character and iter to the next position of rgv[1].   

