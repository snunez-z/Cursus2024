## Commented Solution


1. Loop to go through the string to the end.
2. A mathematical operation is needed in which if I add 1 and I go over the maximum value, which in this case is Z, I start from the beginning, which in this case is A.
That mathematical operation is the modulus %, in this case % 26, which means that it is limited between 0 and 25.
3. For each character if it is between 'A' and 'Z', the value of each position is subtracted from the value of 'A' to get the reference of its value to start from zero.    
    - These are the values ​​that we need to handle the modulus.
    - Example = if it is a B, it will be 1 because A will be 0 and B will be 1
            if it is a D, it will be 3 because A will be 0, B 1, C 2 and D 3
4. After taking its value relative to zero, we add 1 because we want the next one.
5. In case we have gone over, we do the modulus % 26, the result will be between 0 and 25, even if we have gone over. 
   Since what we want is not between 0 and 25 but between 65 'A' and 90 'Z', we have to add 65 to the result of the modulus. Example string: BZ
B = Equals 66 -> 66 - 65 = 1 --> +1 = 2 -->2 % 26 = remainder 2 --> + 65 = 67 which in ASCII is C.
Z = Equals 90 -> 90 - 65 = 25 -> +1 = 26 ->26 % 26 = remainder 0-> +65 = 65 which in ASCII is A.
6. Write every character.
7. Iter to the next position i++.
8. At the end, write \n.