#include <stdio.h>
#include "libft.h"

int ft_count_words(char* str, int separator)
{
   int     words;
   char    *aux;

   // Excepcion
   if (ft_strlen(str) == 0)
       return 0;
    
   words = 0;
   aux = str;
   while (aux != 0)
   {
       aux = ft_strchr(aux, separator);
       if (aux != 0)
           aux++;
       words++;
   }

   return words;
}

char** ft_split(char *str, int separator)
{
   char    **words;
   int     num_words;
   char    *from;
   char    *to;
   int     index;

   num_words = ft_count_words(str, separator);
   words = (char**) ft_calloc(num_words + 1, sizeof(char*));

   index = 0;
   from = str;
   while (from != 0)
   {
       to = ft_strchr(from, separator);
       if (to != 0)
       {
           words[index] = ft_substr(from, 0, to - from);
           from = to + 1;
       }
       else
       {
           words[index] = ft_substr(from, 0, ft_strlen(from));
           from = to;
       }
       index++;
   }

   return words;
}

int main(void)
{
   int index;
   char** split;

   split = ft_split("Susana Núñez Zamora", ' ');
   index = 0;
   while(split[index] != 0)
   {
       printf("%s\n", split[index]);
       index++;
   }

   return (0);
}
