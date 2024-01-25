#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int ft_count_words(char* str, char separator)
{
   int     words;
   char    *aux;

   words = 0;
   aux = str;
   while (*aux != '\0')
   {
       // Nos saltamos todos los separadores que haya antes de la palabra
       while (*aux == separator && *aux != '\0')
           aux++;

       // Hay dos posibilidades: Que hayamos encontrado una palabra o que
       // hayamos llegado al final de la cadena. Sólo podemos contabilizar
       // una palabra más si no hemos llegado al final de la cadena
       if (*aux != '\0')
           words++;

       // Vale, tenemos una palabra. Ahora tenemos que "saltarnos la
       // palabra", o sea, llegar al siguiente separador
       while (*aux != separator && *aux != '\0')
           aux++;
   }

   return words;
}

static void ft_free_all_reserved_memory(char** words)
{
    int index;

    // Primero tenemos que liberar el espacio que se hubiese reservado para
    // cada palabra. La primera palabra estará en words[0], la segunda en
    // words[1] y así sucesivamente
    index = 0;
    while(words[index] != 0)
    {
        free(words[index]);
        index++;
    }

    // Una vez liberadas todas las palabras, podemos liberar el array en sí
    free(words);
}

static int find_words_into_string(char *str, char **words, int divider)
{
    char    *from;
    char    *to;
    int     index;

    index = 0;
    from = str;
    while (*from != 0)
    {
        for ( ; *from == divider && *from != '\0'; from++);
        if (*from != '\0')
        {
            for (to = from; *to != divider && *to != '\0'; to++);
            words[index] = ft_substr(from, 0, to - from);
            if (words[index] == 0)
                return (0); // false. Error
            from = to;
            index++;
        }
    }
    return (1); // true. Todo ha ido bien
}

char** ft_split(char *str, char separator)
{
    char    **words;
    int     num_words;

    if (str == 0)
        return (0);

    num_words = ft_count_words(str, separator);
    words = (char**) ft_calloc(num_words + 1, sizeof(char*));

    if (find_words_into_string(str, words, separator) == 0)
    {
        ft_free_all_reserved_memory(words);
        return (0);
    }

    return words;
}

int main(void)
{
   int index;
   char** split;

   split = ft_split("     Susana        Núñez         Zamora            ", ' ');
   // split = ft_split("Susana", ' ');
   // split = ft_split("", ' ');
   index = 0;
   while(split[index] != 0)
   {
       printf("[%s]\n", split[index]);
       index++;
   }

   return (0);
}
/*
int main(void)
{
    printf("%d\n", ft_count_words("    Susana    Nunez    Zamora    ", ' '));
    printf("%d\n", ft_count_words("", ' '));
    printf("%d\n", ft_count_words("   ", ' '));
    printf("%d\n", ft_count_words("Susana", ' '));
}
*/
