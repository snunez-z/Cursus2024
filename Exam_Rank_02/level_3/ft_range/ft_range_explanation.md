 ## Commented Solution

t could be that the number of numbers between start and end does not fit in an int, for example if we are given the maximum positive number and the maximum negative number, so we must declare the variable num_numbers and the index as long.
At the same time we need that the start & end variables to be interpreted as a long to contemplate the case of maximums positive and negative, to make sure that the numbers of the array numbers has the capacity to fill all the numbers.
1. We are going to declare an array of numbers where to put the result.Protection for memory reservation.
2. To allocate memory we need to know how many numbers will be contained in that array of numbers that starts with one and ends with another number. We don't know how many numbers there are between the beginning and the end.
3. How to find out? 
   We have two cases :
   - If start is smaller than the end.
   	- Then num_numbers = we will subtract start - end & add one more for the \0.
   	- inc variable = 1 to increase 1 to find the next one .
   - But if start is bigger than the end.
 	-Then num_numers = we will subtract the end - start & add one more for the \0.
	- inc variable = -1 to increase to find the next one.
4. Reserve memory for the array numbers.
5. Index  = 0 and loop with condition to index is smaller than the quantity of numbers.
   -The starting number is placed in the first position.
   -The next number is moved on to the next one by incrementing inc.
   -The loop is exited when the number of numbers available is reached.
6. Return the array of numbers. 


