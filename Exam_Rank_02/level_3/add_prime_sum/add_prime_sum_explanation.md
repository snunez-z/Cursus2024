## Commented Solution

We are asked to add all the prime numbers below an integer that we receive as an argument, including the number received.

1. For this we create a function "is_prime" to detect if one number is prime or not.
   - The function consist in a loop with the condition that the index doesn't reach the number.
   - The variable i (index) is initialized to 2 because this is the first number by which it makes sense to divide num.
   - A num is prime when it is only divisible by 1 and by itself. 
     It does not make sense to divide num by 1, since any number is divisible by 1 and this does not provide useful information for determining whether num is prime.
   - If the num divided by the value of index is cero, this means that it is not a prime number, so return 0 and exit.
   - If the num divided by the value of index is != of cero, this means that it is a prime number, return 1.
2. We need a function "ft_atoi" to convert an array of number into an integer.
3. we need a function "putnbr" to be able to write digit by digit the number.
4. The program:
   - We declare the variable num to collect the value of the number received.
   - We declare the variable add to collect the operation requested as a result.
   - Corner case : exit and display 0\n if there is not enough arguments < 2 to do the operation or if it is a negative number.
   - num = the result of calling the "ft_atoi" function.
   - Now we have to add the prime numbers found, so add variable starts in cero value.
   - While the num will be bigger than 1 if it is a prime number :
     add variable will be equal to the value of add + this number.
    
   - iter from right to left -- num. 
     Example 7 --> 7 is smaller than 1,is not prime so add go on with value 0 and the iteration is at 6 number.
5. When it exits the loop, it calls the "ft_ put_nbr" function to write the result of add and ends with a line break.           
    
