/*Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>*/
#include <unistd.h>

int main (int argc, char **argv)
{
	char *str;
	int	i;

	if (argc == 2)
	{
		str = argv [1];
		i = 0;
		while (str [i] != '\0')
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = (str[i] - 'A' + 13) % 26 - 'A';
			else if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = (str[i] - 'a' + 13) % 26 - 'a';
			write (1, &str[i], 1);
			i++;
		}
	write (1, "\n", 1);
	return (0);
	}
}


/*
int	main(int argc, char **argv)
{
	char	*str;
	int	i;

	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (str[i] != '\0')
		{	
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 13;
				if (str[i] > 'Z')
					str[i]-= 26;
			}
			else if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] += 13;
				if (str[i] > 'z')
					str[i] -= 26;
			}
			write(1, &str[i], 1);
			i++;
		}
	
	}	
	write (1, "\n", 1);
	return (0);
}
*/























/*
int main (int argc, char**argv)
{
    	int 	index;
	char	*str;	   
    
	index = 0;
	str = argv [1];
    	if (argc == 2)
    	{
        	while (str[index] != '\0')
        	{
            	if ( str[index] >= 'a' && str[index] <= 'z')
                	str[index] = (str[index] - 'a' + 13) % 26 + 'a'; 
            	else if (str[index] >= 'A' && str[index] <= 'Z')
            	{	
                	str[index] += 13;
                	if (str[index] > 'Z')
                    		str[index] -= 26;
            	}
            write (1, &str[index], 1);
            index++;
        }
        write(1, "\n", 1);
        return (0);
    }
}*/

