# Commented solution

1. Number of arguments is equal to number of argc.
   We have to substract one (-1) because the first argument is always the programme name.
   So my programme only need to display the value of (argc - 1).
   As we can not use printf, the only way to display a number is writing our own putnbr function.
