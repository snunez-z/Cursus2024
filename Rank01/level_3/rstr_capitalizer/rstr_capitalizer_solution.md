#Commented Solution

1. Corner case if they do not pass any parametre, display \n and leave the programme.
2. As we don´t know how many string we are going to received, we declare an index and while index < argc, we are contemplating as many argvs possible
3. We go through the string position by position and for each, if character is lowercase and its next position [j + 1] is a space or the end of the string, then in that position we change that character from lowercase to uppercase.
4. But if it is a capital letter and it is the next position [j + 1] is not a space and it is not the end of the string, the character is changed from uppercase to lowercase.
5. The write character by character, itering the position and when you have gone through the entire chain, you put a line break and iterate to the next parameter if there is one. 
