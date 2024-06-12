#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void store_bits(char ch, int *buffer, int start_index)
{
    int mask = 128;
    int index = 0;
    
    while (index < 8)
    {
        int bit = (ch & mask);
        if (bit == 0)
            buffer[index] = SIGUSR1;
        else
            buffer[index] = SIGUSR2;

        buffer[index]++;
        mask = mask / 2;
        index++;
    }
}

void print_bits(int *buffer)
{
    int n = 0;
    while (n < 8)
    {
        printf("%d", buffer[n]);
        n++;
    }
    printf("\n");
}

int* message_to_signals(const char *message)
{
    int num_chars;
    int num_bits ;
    int *buffer;
    int char_index;
    int bit_index;
    
    num_chars = strlen (message) + 1;
    num_bits = num_chars * 8;
    buffer = malloc (num_bits * sizeof(int));
    if (buffer == NULL)
        return (NULL);
    char_index = 0;
    bit_index= 0;
    while (char_index < num_chars)
    {
        store_bits(message, bit_index, char_index);
    }
    char_index++;
    bit_index = bit_index + 8;
    return (buffer);
}   
int main(int argc, char **argv)
{
    int     pid;
    char    *bits;
     
    if (argc < 2 )
    {
        printf("usage %s <file> \n", argv [0]);
        return (1);
    }
    pid =atoi (argv[1]);
    if (pid == 0)
   {
      printf("PID Invalido\n");
      return (-1);
   }
    bits = message_to_signals (argv[2]);
    if (kill (pid, SIGUSR1 == -1) || kill (pid, SIGUSR2 == -1));
    { 
        printf("No se ha podido enviar la señal");
        return (1);
    }                
    kill (pid, SIGUSR1);
    printf("Señal SIGUSR1 enviada al proceso con pid %d\n", pid);
    kill (pid, SIGUSR2);  
    printf("Señal SIGUSR2 enviada al proceso con pid %d\n", pid);
    free (bits);
    return (0);
}
