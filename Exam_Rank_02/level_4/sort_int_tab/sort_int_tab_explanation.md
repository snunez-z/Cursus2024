## Commented Solution

In the exercise we are asked to sort an array from smallest to largest but overwriting the same array. 
Therefore we cannot take it to another array and use malloc, we have to do it another way.
Looking for the position where the largest number is, taking its value to an auxiliary, take the value of the last position [size - 1] and from there search in smaller array **RECURSIVITY**

So we create a function which search the maximum number in one number,s array and return **its position.**

**search_max** function
We need the position of this maximum number to be able to exchange numbers in sort_int_tab function.

1. This function need to receive array of numbers and the quantity of numbers the array has.
2. We declare a counter i to put it as a condition.
3. We declare a int variable max that it is starts with the first position of numbers.
4. While the counter doesn´t reach the quantity of numbers.
5. If the number is greater than the one is in the max variable, ths vaule is placed into thsi variable.
6. the index j = i to indicate that the position of elder for now is that.
7. Iter the counter to the next position.
8. When we finishes, display the position.

**sort_int_tab** function

We place the largest number in the last position. 
From there we **recursively** call each other to place the largest number in the last position but with an array of smaller numbers. 
The end of recursion will occur when there is a single number or less than 1 single number.

1. We declare an int variable to collect the position of the biggest number of the array received.
2. We declare an int variable **aux**to collect the value of the biggest number of the array received.
3. Corner case if we received only one number, there is no point in ordering.
4. We call the funcion **seach_max** and inside the auxiliary we put its value.
5. In the position where the largest value was, we put the value of the last position [size - 1].
6. And in the last posiion we put the largest value which was stored in auxiliary variable.
7. Now we call ourselves with a smaller search because we already have the largest number at the end.
   -Example = 5872 -> 5278 -> 5278 -> 2578 

