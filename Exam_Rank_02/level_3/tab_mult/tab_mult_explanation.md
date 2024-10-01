## Commented Solution

1. We need a function that receives a string with numbers and converts them into a number. The "ft_atoi" function will convert a const char * into an int taking into account whether it is negative or positive.
2. As we only can use "write" function, we need a function "putnbr" that receives a number that, if it is larger than a figure, calls itself by dividing by 10, to get the last figure and thus be able to display each digit of the number on the screen.
3. The exercise ask us to write the whole operation " 1 x 1 = 1" and using only "write" function, so we need a function "nultiplication"which calling "putnbr" function and using wr:wqite for maths symbols you can display the entire operation on the screen, including its result.
4. The program will control the arguments received. DEclare a variable int to collect the result of ft_atoi, call multiplication function and return 0.
