/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunez-z <snunez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:10:08 by snunez-z          #+#    #+#             */
/*   Updated: 2024/06/18 11:01:53 by snunez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include "libft/libft.h"

int    *signals;
int     num_signals;
int     signal_index;

static void char_to_signals(char ch, int *buffer, int start_index) // Necesita recibir el caracter a convertir, el buffer donde guardar los bits y desde donde dentro del array guarda los bits 
{
    //   0 1 0 0 1 0 0 0 = 72 = 'H'
    // & 1 0 0 0 0 0 0 0 = 128 = mask
    //   ---------------
    //   0 0 0 0 0 0 0 0 = 0
    int mask = 128;
    int bit_index = 0;
    int bit;
    
    while (bit_index < 8)
    {
        bit = (ch & mask);
        if (bit == 0)
            buffer[start_index] = SIGUSR1;
        else
            buffer[start_index] = SIGUSR2;

        start_index++;
        mask = mask / 2;
        bit_index++;
    }
}

static void message_to_signals(const char *message)
{
    int num_chars;
    int char_index;
    int start_index;
    
    num_chars = ft_strlen (message) + 1;
    num_signals = num_chars * 8;
    signals = malloc (num_signals * sizeof(int));
    if (signals == NULL)
        return;
    char_index = 0;
    start_index= 0;
    while (char_index < num_chars)
    {
        // 1 parámetro: Qué caracter
        // 2 parámetro: Dónde guardar los bits
        // 3 parámetro: Desde donde (dentro del array) guardar los bits
        char_to_signals(message[char_index], signals, start_index);
        char_index++;
        start_index = start_index + 8;
    }
}   

void handler_sigusr1 (int sign, siginfo_t *siginfo, void *context) 
{
    (void)sign;
    (void)context;

    if (signal_index >= num_signals)
        return;

    usleep(10);
    if (kill(siginfo->si_pid, signals[signal_index]) < 0)
    {
        ft_printf("Error sending signal to server with PID %d\n", siginfo->si_pid);
        exit(-1);
    }
    signal_index++;
}

int main(int argc, char **argv) // Lo que hago es recorrer el mensaje y enviar señales al server por cada caracter.
{
   struct sigaction sa;
    int     pid;
     
    if (argc < 3 )
    {
        ft_printf("usage %s <file> \n", argv [0]);
        return (1);
    }
    pid =ft_atoi (argv[1]);
    if (pid == 0)
   {
      ft_printf("PID Invalido\n");
      return (-1);
   }
        
   ft_memset (&sa, 0, sizeof(sa)); 
   sa.sa_sigaction = handler_sigusr1; //donde, a que funcion hay que llamar cuando llegue la señal
   sa.sa_flags = SA_SIGINFO; // Definimos como queremos que nos llegue la señal, con info o sin info
   if(sigaction (SIGUSR1, &sa, NULL) < 0)
   {
       ft_printf("Error listening to signals\n");
       return (-1);
   }
   message_to_signals (argv[2]);  

    // En la variable "pid" tenemos el PID del server
    // En la variable signals tenemos el array con las señales a enviar
	signal_index = 1;
    if (kill(pid, signals[0]) < 0)
    {
        ft_printf("Error sending first signal\n");
        return (-1);
    }

    while (signal_index < num_signals)
        pause();
    free (signals);
    return (0);
}
