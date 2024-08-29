## Commented Solution

1. If we received more than 1 argument and the argument is not empty. We can go into the keys.
2. We need to separate and narrow down the first word, so we declare an index to go throw the loop.
3. We need to declare the start variable and the end variable to mark the start and end of the first word.
4. We should contemplate teh posibility to receive at the begining of teh string tabs and spaces. So the first thing to do y is to jump the spaces and tabs.
5. When we find the first char of the first word we give the value of i to start.
6. We go thorugh the word, itering i and when we find the end of the word because we find a space, now end value the same than i.
Now the first word is controled.
we asumme that the new string is from this first word.

7. So, loop to go through to the string at the end.
8. While the char it is not and space or tab, **write the chars** one by one itering index 9. Write the space. 
10. While the char is an space or tab iterate index. And when the loop finishes because the last char is a '\0'...

We should write the first word that we have delimited by start and end.
The first word starts in start variable and finishes in end.
Example = "  Que  la suerte te acompañe"
start = 2
end = 5
We have to write what is between start and end, which is the subtraction between end and start.

11. So write (1, &str [start], end -start).
12. Finish with break line \n.


