#include <stdio.h>

static int ft_strlen(char *buffer)
{
    int len = 0;
    while (buffer[len] != '\0')
        len++;
    return len;
}

static void read_word(char *buffer)
{
    printf("Escribe una o mas palabras: ");
    scanf("%s", buffer);
}

static char give_me_one_char()
{
    static char word[100];
    static int index = 0;
    static int len = 0;
    char ch;

    if (index >= len)
    {
        read_word(word);
        index = 0;
        len = ft_strlen(word);
    }

    ch = word[index];
    index++;
    return ch;
}

int main(void)
{
    char ch;

    while(1)
    {
        ch = give_me_one_char();
        printf("%c\n", ch);
    }
}

