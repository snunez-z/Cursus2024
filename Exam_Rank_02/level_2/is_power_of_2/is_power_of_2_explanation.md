## Commented Solution

1. As cero is not a power of 2, exit.
2. As long as n is divisible by 2 and its remainder is zero.
   in every iteration the number is divided by 2 till it is not longer divisible by 2.
3. Only in the case the the remainder will is 1, the number is divisible by 2.
   So return (1) to indicate it .
   Example :
   n = 32 32/2 = 16 16/2 = 8 8/2 = 4 4/2 = 1 
   n = 15 15/2 = 7 7/2 = 3 Reminder = 3 different from 1
    
4. Else return (0) to indicate that it is not a a number oower of 2.

