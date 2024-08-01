# Commented Solution

1. We need to know the size of str. For this we declare a variable len and initialize to cero.
2. Loop to run the str till the end.So len = len - 1 , to position in the previous pos before '\0'.
3. Declare and initialize an index. Loop with the condition to an index doesn't reach the len.
4. We need to exchange one by one the last character of the string with the first, from outside to inside.
5. So the auxiliary keep the content of the first position  
6. In this position we put in the content of the last position.
8. In the position of len you put in the content of the first position.
9. Then iterate the indexs from left to right and len from right to left.
10. Return the pointer to str.
