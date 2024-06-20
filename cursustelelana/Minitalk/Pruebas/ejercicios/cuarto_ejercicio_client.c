
/*In the "client.c" file, you will...
Write a program (main) in which the client takes two parameters/arguments
The PID of the server to which it wants to send the message
A message
Encrypt the message (I did the encryption via bits)
Send the message to the server (via its PID)
Create a stop condition so that the server knows when it has finished receiving the message*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char **argv)
{
   int pid;
   char  *str;

	if (argc < 2) 
   {
      printf("usage %s <file> ...\n", argv[0]);
		return (-1);
   }
   pid = atoi(argv[1]);
   if (pid == 0)
   {
        printf("PID inválido.\n");
        return 1;
   }
   if(kill(pid, SIGUSR1) == -1 || kill(pid, SIGUSR2) == -1)
   {
      printf("No he podido enviar la señal.\n");
      return (1);  
   }
   kill(pid, SIGUSR1);
   printf("Señal SIGUSR1 enviada al proceso con PID %d\n", pid);
   kill(pid, SIGUSR2);
   printf("SEñal SIGUSR2 enviada al proceso con PID %d\n", pid);
   return (0);
}
