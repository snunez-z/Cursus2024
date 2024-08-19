## Commented Solution

It could be that the number of numbers between start and end does not fit in an int, for example if we are given the maximum positive number and the maximum negative number, so we must declare the variable num_numbers and the index as long.At the same time we need that the start & end variables to be interpreted as a long to contemplate the case of maximums positive and negative, to make sure that the numbers of the array mumbers has the capacity to fill all the numbers.
1. We need to declare an array to put the numbers there. *numbers.
2. We need to declare a varible to know how many numbers are between end and start, a long. num_numbers.
3. We need to declare an index of long type becuase it could be posible that the numbers of positions may not fit into an int because they pass the positive maximum at one end and the negative maximum at the other end.
We need to declare a value variable to collect the vaules from the end to start
4. There are two cases, that the end is greater than the start or vice versa.
   If start is smaller or equal than the end sustract end - start + 1 (to include the end).
   Is the start is bigger than the end sustract start - end + 1 (ito include the start).
5. Reserve memory for the array.Protection for reservation.
6. Value of value is end. Index value is 0.
7. Loop with teh condition that the index doent reach the num_numbers.
   - In every position of numbers we will put the value of value variable.
   - If the start is smaller or equal than end, value sustracted.
   - If the start is bigger or equal than end, value is added.
8. In both cases the index advance ++.
9. Return the position of the array numbers.

