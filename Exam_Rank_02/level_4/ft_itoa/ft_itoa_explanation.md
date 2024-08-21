## Commented Solution


**ft_atoi** Function

1. We declare a char * to put the converted number.
2. We declare a last_index to put every char position by position in the array later.
3. We reserve memory for the char * num by calling the **ft_con_len** function that returns the size of the number we received.
4. If the reservation fails, exit.	 
5. if the number received is 0, put the digit '0', the '\0' and exit.
6. if the number is negative, in the first position, put the symbol -.
7. We position ourselves at the last_digit by calling the **ft_cont_len** function and subtracting 2 - skip the '\0' and place ourselves at the next one.
	- Number = 1253 -> last_index = 3 ( 5 - 3) .
8. Loop with the condition that as long as the number received is not cero .
   - Into array num = last digit (obtained by calling the **last_digit** function that returns the last digit converted to char).
   - nbr variable holds the value of the number / 10 that remains once we have passed the last digit.
   - With last_index -- we advance from right to left through the number until last_index, the counter reaches zero.		 
9. Display * of array num.	
- We are going to received an array of numbers , nut we don`t know how many digits this number has.
- So we need a function thats receives the int with the number and display the size of the number.


** ft_cont_len** function.
~~~
1. **ft_cont_len** function displays us the size of the number array received by screen.
2. Corner case = if the number is 0, the size is (1 + '\0'), so display 2 and exit.
3. Now we have to contemplate if the num is positive or negative to include or no the simbol -.
4. Loop till the end of the number.
   - We divide /10 to rduce a digit the number
   - Advance 1 size_num
5. Return size_num + 1 to take into account the '\0';	
~~~
**last_digit** Function

~~~
- As long as we know the size of the number, now we now to extract digit to digit to be able to convert it into char.
- Using the % we can know last digit.
  Example : 12 % 10 = remainder is 2 
- So we need a function to detect the last digit and convert it into a char.

1. **last_digit* function detects the last digit considering two cases.
	- If the number is positive (extracts the last digit with the module operation) and the value of the digit char is added to the value of the char of '0'.
	- if the number is negative. 
		- Example -> 12 -> last digit is 2->  2 + value in ASCCI of '0' is 48 -> so 50 is = Digit 2 in ASCCI.
		- Example -> -12 -> last digit is -2->  -2 - value in ASCCI of '0' is 48 -> so 50 is = Digit 2 in ASCCI.
	 
~~~


	

