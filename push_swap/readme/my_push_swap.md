## Push Swap

Push_swap es un proyecto que consiste en ordenar una serie de numeros contando con conjunto limitado de operaciones que nos dan y 
en numero limitado de uso. Hay que sistematizar una solucion y utilizar un algortimo que funcione.

**Conceptos Basicos**

__El ensamblador__ es el lenguaje del procesador. El concepto de pila viene de esos tiempos, es la forma que tiene el procesador y el lenguaje C y cualquier otro lenguaje de programacion de soportar llamadas entre funciones,porque los datos de cada funcion se guardan en la pila encima de los datos de la funcion que llama a esa funcion.
Cuando una funcion acaba, se quita de la pila los datos que usaba.

**Ejecucion 1** 
En el stack estarian las dos variables que usa esa funcion :

	a-> funcion 1
	b-> funcion 1

**Ejecucion 2**
La funcion 1 llama a la funcion2 funcion2
el stack apila las variables de la funcion2 encima de las varibales de la funcion 1
	a->funcion2
	b-> funcion2
	a-> funcion1
	b-> funcion1
**Ejecucion 3**
Cuando acaba de ejecutarse en la funcion 1, la funcion 2 que ha sido llamada el stack,
se borran las variables que no se usan.

	a-> funcion 1
	b--> funcion 1
**Ejecucion 4**
Cuando acaba de ejecutar la funcion 1, el stack se queda vacio.

__Operacion minimas del stack__

Hay dos operaciones minimas que se hacen para manejar un stack.
PUSH -> apila 1 dato
POP-> saca el ultimo elemento que se añadió en la pila.

**Operaciones permitidas**

. sa swap a: Intercambia los dos primeros elementos del stack a. N
. sb swap b: Intercambia los dos primeros elementos del stack b. 
. ss swap a y swap b a la vez.
. pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
  a. No hace nada si b está vacío.
. pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
  b. No hace nada si a está vacío.
. ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
  de forma que el primer elemento se convierte en el último.
. rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
  de forma que el primer elemento se convierte en el último.
. rr ra y rb al mismo tiempo.
. rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una
  posición, de forma que el último elemento se convierte en el primero.
. rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una
  posición, de forma que el último elemento se convierte en el primero.
. rrr rra y rrb al mismo tiempo.

**Algoritmo**

1.- __Main.c__
El programa se ejecuta desde el main.c. 
SE declaran las dos pilas del tio de la estructura t_stack_list *.

.- Si argc es mayor que 1, o que hay mas argumentos que el nimbre del programa el programa no entra y no haria nada, devolveria el control al usuario.
el indice empieza en 1. y declaramos las pilas como vacias, apuntando a NULL.
.- Bucle para recorrer todos lso argumentos que haya, mientras el indice que empieza en 1, porque en cero está el nombre del programa.
.- Dentro del  bucle, si la funcion de parseo (parse_arv) encuentra errores libera, da el mensaje de error y se sale.
.- Si sale todo bien, y estan metidos en la pila a los numeros y pasa a dependiendo de la cantidad de numeros que haya entrará en un sistema de ordenamiento u otro.
.- Hasta 10 llamará a la funcion de ordenamiento sort_few_numbers, pasandole la direccion de memoria donde se encuentran las pilas (a y b). 
. A partir de 10, se llama a la funcion enumerate_index_nodes (a) -> esta funcion lo que hace es recorrer la pila 




