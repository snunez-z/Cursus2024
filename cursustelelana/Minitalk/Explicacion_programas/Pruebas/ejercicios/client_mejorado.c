#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

int     ind = 1;
int num_signals;
int *signals;

static void char_to_signals(char ch, int *buffer, int start_index) // Necesita recibir el caracter a convertir, el buffer donde guardar los bits y desde donde dentro del array guarda los bits 
{
    //   0 1 0 0 1 0 0 0 = 72 = 'H'
    // & 1 0 0 0 0 0 0 0 = 128 = mask
    //   ---------------
    //   0 0 0 0 0 0 0 0 = 0
    int mask = 128;
    int count = 0;
    int bit;
    
    while (count < 8)
    {
        bit = (ch & mask);
        if (bit == 0)
            buffer[start_index] = SIGUSR1;
        else
            buffer[start_index] = SIGUSR2;

        start_index++;
        mask = mask / 2;
        count++;
    }
}

static int* message_to_signals(const char *message)
{
    int num_chars;
    int num_bits ;
    int *buffer;
    int char_index;
    int start_index;
    
    num_chars = strlen (message) + 1;
    num_bits = num_chars * 8;
    buffer = malloc (num_bits * sizeof(int));
    if (buffer == NULL)
        return (NULL);
    char_index = 0;
    start_index= 0;
    while (char_index < num_chars)
    {
        // 1 parámetro: Qué caracter
        // 2 parámetro: Dónde guardar los bits
        // 3 parámetro: Desde donde (dentro del array) guardar los bits
        char_to_signals(message[char_index], buffer, start_index);
        char_index++;
        start_index = start_index + 8;
    }
    return (buffer);
}   

void handle_sigusr1(int sig, siginfo_t *siginfo, void *context)
{
    (void)context; 
    int result_send_signal;

    if (ind < num_signals)
    {
        result_send_signal = kill(siginfo->si_pid, signals[ind]);
        if (result_send_signal == -1)
		{	
            printf("Failed to send signal\n");
            return;
		}
        printf(" Signal sent to process to PID %d\n", siginfo->si_pid);                 
        ind++;
    }
}

int main(int argc, char **argv) // Lo que hago es recorrer el mensaje y enviar señales al server por cada caracter.
{
    int     num_chars;
    struct sigaction sa;
	int pid;
         
    if (argc < 3 )
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
    memset(&sa, 0, sizeof(sa)); 
    sa.sa_sigaction = handle_sigusr1;
    sa.sa_flags = SA_SIGINFO;  
    if(sigaction(SIGUSR1, &sa, NULL) == -1) 
    {
        printf("Handler is not listening\n");
        return (-1);
    }
    num_chars = strlen (argv[2]) + 1;
    num_signals = num_chars * 8;
    signals = message_to_signals (argv[2]);
    if (signals == NULL)
        printf("Unable to send initial signal\n"); 

    if(kill(pid, signals[0]) == -1) // Este va a inicializar una vez, el resto seria responsabilidad del handler
    {
        printf("No he podido enviar la señal.\n");
        return (1);  
    }
    printf("Sign send to process PID %d\n", pid);
    while (1)
        pause();
    free (signals);
    return (0);
}
