
/* Modifica tu server para que pueda recibir señales SIGUSR1
   Cuando reciba una, tiene que mostrar el mensaje
   "SIGUSR1 received from PID <el pid del remitente de la señal>"
   
   Modifica el cliente para que envíe una señal SIGUSR1 al PID que le han pasado
   como parámetro

   La vas a cagar en este (en la parte del server). Cuando veas que no te funciona
   dímelo*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
   int pid;

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
	
	if(kill(pid, SIGUSR1) == -1)
	{
      printf("No he podido enviar la señal.\n");
      return (1);  
   }

	printf("Señal SIGUSR1 enviada al proceso con PID %d\n", pid);
   return 0;
}