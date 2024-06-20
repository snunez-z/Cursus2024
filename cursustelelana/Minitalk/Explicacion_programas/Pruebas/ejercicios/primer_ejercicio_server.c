/*Haz un server que muestre por pantalla (printf) su PID
   NADA DE SEÑALES. Sólo mostrar su PID y acaba

   Haz un cliente que reciba como parámetro un número (argv[1])
   Si no lo recibe, tiene que mostrar el usage típo:
   "usage ... <PID>"
   Si lo recibe, tiene que mostrar "Connecting to PID <el pid que hayan pasado>"

   NADA DE SEÑALES. Sólo eso*/

#include <stdio.h>
#include <unistd.h>

int main ()
{
   printf("Server PID = %d\n", getpid());
   return (0);
}
