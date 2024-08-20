## Commented solution.

Prime factorization is the representation of a number as a multiplication of prime numbers.
Example -> 42 = 2*3*7
           43 = 43

A number is prime when it is not divisible (zero remainder) from 2 to the value of that number.
Example: 42 is divisible by 2, therefore it is not a prime number.
         43 is not divisible by 2, nor by 3, nor by 4... it is prime, it is only divisible by it
         self and by 

The exercise asks us to display on the screen the decomposition into prime factors of a number.
So our programme will follow the following steps:
1. We declare a variable num where we will save the result of converting argv[1] (the on-screen parameter into an integer.)
2. If it receives two parameters it continues, if not it displays a line break on the screen and ends.
3. We call to the **fprime** function.
   - This function receives the integer.
   - If the integer is 1, corner case, print 1 and exit.
   - We declare a variable called factor, that it is inialised at 2. The first prime number.
   - We know that we have to divide the number that is given to us by the factors from 2 until the number that we divide is 1.
      - Example: 50 is divisible by the factor 2 = 25
                 25 is divisble by the factor 5 = 5
                  5  is divisible by the factor 5 = 1
                  So the value of num at the end is = 1
   - Loop with the condition as long as the number is greater than 1, factor variable will add 1.
   - Inside the loop there is another loop that checks if the division of the number by the factor has a remainder of zero. 
   - In that case, we know that it is divisible and since we started with a prime number we also know that it is a prime number.
   - Besides, we are in a loop,numbers are divided by every factor as many times as the remainder of its result is zero.
     So if the factor is 2 -> 4 ( 2*2), 8 (2*2*2*2), 10 (2*2*2*2*2) ......are going to be discarded
- Therefore, we can print the factor with the certainty that it is a prime number.
- the number is devided for the next factor.
- If the number is grater than 1, we should print teh symbol *, when the number is 1, when the number reaches 1, we will have printed the last factor and it will no longer be necessary to put the * symbol.
4. when we exit of teh loop, we print \n.
