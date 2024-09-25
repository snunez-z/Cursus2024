## Commented Solution

We have to take into account two things:
1.- We have to write each letter that is passed to us in an array as many times as its position in the alphabet.
2.- If it is not a letter, it is written as it is and only once.

To know what position it has in the alphabet you have to subtract the value of the letter and add one.
Example = a
a = a position 1.
If the character I receive is c (value 99) by subtracting a (value 97) the result is 2.
But the position that c occupies is 3, so we will always have to add 1 to give us the real position in the alphabet.
We will add 1 to the character that they pass us and then we will subtract a. 
In this way we will know the position that any letter occupies in the alphabet, as long as it is a letter.
That position will be the one we pass as an int type argument to a function that writes each character we pass to it as many times as that int indicates.

1. It is created a function "ft_putchar" that is responsible for painting a character as many times as indicated by a variable of type int 
2. It is created a function "repeat_alpha" that runs through a string and as long as it does not reach '\0' , it checks that the character 
   is a lowercase or uppercase letter and calls putchar to write it and if not, it simply writes the character. 
3. The programa called the function repeat_alpha passing the argument argv[1] and then write a line break.
