# Commented Solution

1. We create a function which search the maximum number in one number,s array and return its position.  We need the position of this maximum number to be able to exchange numbers in sort_int_tab function.
2. We place the largest number in the last position. From there we recursively call each other to place the largest number in the last position but with an array of smaller numbers. The end of recursion will occur when there is a single number or less than 1 single number.
