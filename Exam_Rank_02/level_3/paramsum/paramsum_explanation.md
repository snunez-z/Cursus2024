## Commented solution

1. Number of arguments is equal to number of argc.
   We have to substract one (-1) because the first argument is always the programme name.
   So my programme only need to display the value of (argc - 1).
   As we can not use printf, the only way to display a number is writing our own putnbr function.
   We need fºit_putnbr funcion to convert the int (argc) into char and reduce the number in case it is more than one digit.
   We wouldn't need putnbr if the argc were less than 9 but we can receive 200 argcs, so we need ft_putnbr to reduce the digits to a single number.
If it were less than 9, adding '0' or 48 to the value of the number would be enough.
