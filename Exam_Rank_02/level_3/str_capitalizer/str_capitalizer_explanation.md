## Commented Solution

1. Corner case if they do not pass any parametre, display \n and leave the programme.
2. As we don`t know how many strings we are going to received, we declare an index and while index < argc, we are contemplating as many argvs possible
3. We go through the string position by position, and for each, if character is lowercase and its previous position [j -1] is a space, then in that position we change that character from lowercase to uppercase.
4. But before, as previous step and asumming that we could received an space or tab in the first position [0] we should put this corner case.
   if j == 0 (first position o there is an space in the first position and besides is a loowercase the character is changed from lowercase to uppercase.
5. For the rest of characters that they are not the first character of every word in the string, we should specify that the position j is bigger than 0, that there is not space before the letter (indicating that there is not the first char of the word)[j - 1] and if the letters are in uppercase,then we should convert them in lowercase. 

The write character by character, itering the position and when you have gone through the entire chain, you put a line break and iterate to the next parameter if there is one. 

