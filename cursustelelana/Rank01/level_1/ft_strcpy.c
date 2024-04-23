/*Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);*/
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int index;

    index = 0;
    while (s2[index] != '\0')
    {
        s1 [index] = s2 [index];
        index++;   
    }
    s1 [index] = '\0';
    return (s1);
}
int main (void)
{
    char    buffer [100];

   ft_strcpy (buffer, "Hola buena amiga");
   printf("%s\n", buffer);
}
