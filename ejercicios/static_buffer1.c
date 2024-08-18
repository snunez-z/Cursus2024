#include <stdio.h>

static size_t ft_strlen(const char *str)
{
    size_t  index;

    index = 0;
    while(str[index]!= '\0')
    {
        index++;
    }
    return (index);  
   
}

static int ft_digit_to_int(char digit)
{
    int num;

    if (digit >= '0' && digit <= '9')
    {
        num = digit - '0';
    }
    return (num);
 }
    
 static int ft_atoi(const char *str)
{
    int index;
    int result;
    int value ;

    result = 0;
    index = 0;
    while (str [index] != '\0')
    {
        
       value = ft_digit_to_int (str [index]);
       result = value + (result * 10);
       index++;
    }
    return (result);
}

static int ft_suma(int a, int b)
{
    int result;

    result = a + b;
    return (result);
}

int main(int argc, char **argv)
{
  
      
    int num1;
    int num2;
    int result;
    
    if(argc < 3)
    {
        printf (" there had been an error");
        return (-1);
    }
 
    num1 = ft_atoi (argv [1]);
    num2 = ft_atoi (argv [2]);
    result = ft_suma (num1, num2);
    printf(" Ek resultado es %d\n", result);
}   


