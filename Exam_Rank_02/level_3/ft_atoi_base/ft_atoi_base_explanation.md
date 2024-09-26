##  Solution

1. We need to create a "to_lower" function that converts uppercase to lowercase to make them equal and for the program to recognize them as the same.
2. We need to create a "digit_to_value" to convert a digit into an integer.
   - In addition to an index, we declare a string of type char called conversion_table that contains the string "0123456789abcdef". 
   - This string represents all possible digits in a hexadecimal system (base 16).
   - Loop to go through the string to the end and compare if the digit matches the digit in the conversion table at that position. 
   - If it matches, it returns, if it does not match, it continues forward iterating to the next digit through the index.
3. "ft_atoi_base" function receives the string and the int base type
   - We should contemplate the fact that we could receive a negative simbol in position [0].
   - Index value will start at 1 if the symbol - is present and 0 if it is not present. Positive array of numbers.
   - Loop to go through the string till the end. 
   - For each character the value = 0 * the base + the result of calling "digit_to_value" in every position.
   - Iter the index till the end.
4. Once outside the loop, if the number is negative, it is multiplied by * -1 to make it positive. 
5. Return value.

