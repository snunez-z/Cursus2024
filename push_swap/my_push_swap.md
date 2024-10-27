## Push Swap

Sistematizar una solucion usando un conjunto limitado de ordenes.

**Conceptos**

__El ensamblador__ es el lenguaje del procesador. Elconcepto de pila viene de esos tiempos, es la forma que tiene el procesaro y el lenguaje C y cualquier otro lenguaje deprogramacion de soportar llamadas entre funciones,porque lso datos de cada funcion se guardan en la pila encima de lso datos de la funcion que llama a esa funcion.
Cuando una funcion acaba , se quita de la pila lso datos que usaba.

**Ejecucion 1** 
En el stack estarian las dos variables que usa esa funcion :

	a-> funcion 1
	b-> funcion 1
**Ejecucion 2**
La funcion1 llama a la funcion2 funcion2
el stack apila las variables de la funcion2 encima de las varibales de la funcion 1
	a->funcion2
	b-> funcion2
	a-> funcion1
	b-> funcion1
**Ejecucion 3**
Cuando acaba de ejecutarse en la funcion 1, la funcion 2 que ha sido llamada el stack,se borran las variables que no se usan.

	a-> funcion 1
	b--> funcion 1
**Ejecucion 4**
Cuando acaba de ejecutar la funcion 1, el stack se queda vacio.

__Operacion minimas del stack__

Hay dos operaciones minimas que se hacen para manejar un stack.
PUSH -> apila 1 dato
POP-> saca el ultimo elemento que se añadió en la pila.
