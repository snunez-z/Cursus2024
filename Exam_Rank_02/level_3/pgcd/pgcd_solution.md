# Commented solution

1. First thing we should do is toconvert the two arguments into positive numbers using atoi function.
2. We have to find the hisgest number by which both numbers are divisible.
   For it, we use a variable cd (common denominator). This will be inistialized to the lowest of the two numbers, because the common denominator has to be equals or lower than the lowest of the two numbers.
3. We loop from that initial cd down to one till we find a value that is divisible between the two numbers.
4. When we find it , we print it.
