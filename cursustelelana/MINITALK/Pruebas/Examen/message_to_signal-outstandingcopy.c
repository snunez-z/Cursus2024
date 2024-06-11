#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fill_signals_for_char(int *array, char ch, int array_index)
{
    int mask = 1;
    int bit_count = 0;

    while(bit_count < 8)
    {
        if ((ch & mask) == 0)
            array[array_index] = SIGUSR1;
        else
            array[array_index] = SIGUSR2;
        array_index++;
        mask = mask * 2;
        bit_count++;
    }
}

int* message_to_signals(const char *message)
{
    int char_count = strlen(message) + 1;
    int array_size = char_count * 8;
    int *array = malloc(array_size * sizeof(int));
    if (array == NULL)
        return (NULL);

    int array_index = 0;
    int char_index = 0;
    while(char_index < char_count)
    {
        fill_signals_for_char(array, message[char_index], array_index);
        array_index = array_index +8;
        char_index++;
    }
    return array;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("usage %s <message>\n", argv[0]);
        return (1);
    }

    int *signals = message_to_signals(argv[1]);
    if (signals == NULL)
    {
        printf("Error reserving memory for the signals\n");
        return (1);
    }
    int num_signals = (strlen(argv[1]) * 8) + 8;
    int n = 0;
    while (n < num_signals)
    {
        if (signals[n] == SIGUSR1)
            printf("SIGUSR1, ");
        else
            printf("SIGUSR2, ");

        n++;
    }
    printf("\n");
    free(signals);
    return (0);
}

