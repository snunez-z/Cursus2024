/*Haz un server que muestre por pantalla (printf) su PID
   NADA DE SEÑALES. Sólo mostrar su PID y acaba

   Haz un cliente que reciba como parámetro un número (argv[1])
   Si no lo recibe, tiene que mostrar el usage típo:
   "usage ... <PID>"
   Si lo recibe, tiene que mostrar "Connecting to PID <el pid que hayan pasado>"

   NADA DE SEÑALES. Sólo eso*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char   **argv)
{
   int pid;
   
   if (argc < 2)
      printf("usage %s <PID>...", argv [0]);
   pid = atoi (argv[1]);
   if (pid == 0)
      printf("usage %d <PID>...", pid);
   else 
      printf("Conecting to PID %d\n", pid);
   return (0);
}
