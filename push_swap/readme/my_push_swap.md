## Push Swap

Push_swap es un proyecto que consiste en ordenar una serie de numeros contando con un conjunto limitado de operaciones que 
nos dan y un número limitado de uso. Hay que sistematizar una solucion y utilizar un algortimo que funcione.

**Conceptos Basicos**

__El ensamblador__ es el lenguaje del procesador. El concepto de pila viene de esos tiempos, es la forma que tiene el procesador 
y el lenguaje C y cualquier otro lenguaje de programacion de soportar llamadas entre funciones,porque los datos de cada funcion 
se guardan en la pila encima de los datos de la funcion que llama a esa funcion.
Cuando una funcion acaba, se quita de la pila los datos que usaba.

**Ejecucion 1** 
En el stack estarian las dos variables que usa esa funcion :

	a-> funcion 1
	b-> funcion 1

**Ejecucion 2**
La funcion 1 llama a la funcion2 funcion2
el stack apila las variables de la funcion2 encima de las varibales de la funcion 1
	a-> funcion2
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

**¿que hace el programa ?**

Tres partes:
1.- Verificar que los parametros que le pasan son correctos.No tiene sentido ordenar nada si no es correcto.
    tanto los numeros de parametros y si son números enteros entre el min y el max. No puede haber numeros repetidos.
2.- Si esta todo correcto se meten en la pila a y con la ayuda de una segunda pila b, hay que ordenarlos.
3.- Ordenarlos , que tiene a su vez varios pasos.
    Hay que ordenarlos y con un numeros limitado de ordenes. 

**Algoritmo**
Los algoritmos que vamos a usar para ordenar son :
.- Si son pocos numeros (hasta 10), buscaremos en la pila a el mas pequeño, lo subiremos arriba y lo pasaremos a la pila b. Asi sucesivamente hasta que la pila a este vacia.
De esta forma tendremos ordenados de mayor a menor los numeros en la pila b.
Ahora los pasaremos a la pila a y los ordenaremos de forma creciente como pide el subject.
ESte algortimo funciona pero para una pila con muchos numeros no es eficiente, no cumple los requisitos que se nso pide en el subject. 100 numeros usando hasta 700 operaciones, 500 numeros usando hasta 5500 operaciones. Por eso usamos un algortimo diferente para ordenar pilas superiores a 10 números.
.- El algoritmo que usamos lo que hace en diferentes pasos, es, utilizando un index con la posicion que deberian tener si estuviesen organizados, agrupa acercando los mas grandes entre si y los colcoa abajo, hace lo mismo con los pequeños y los pasa a la pila b, de forma que al final, cuando la pila a esta vacia, los más pequeños estan cerca entre si (la mayoria) y los más grandes entre si (la mayoria), los mas pequeños en la parte de abajo y los mas grandes en la parte de arriba.
Los organiza, no los ordena pero los organiza y los acerca. Asi se ahorran operaciones.
Termina de organizarlos en la pila b y luego los pasa a la pila a.  

1.- __Main.c__

El programa se ejecuta desde el main.

Parte 1 y 2: Verificar y meter los numeros en la pila a

Se declaran las dos pilas del tipo de la estructura t_stack_list *.
- Si argc es mayor que 1, que significa que si no hay mas argumentos que el nombre del programa, el 
programa no entra y no haria nada, devolveria el control al usuario.
El indice empieza en 1. y declaramos las pilas como vacias, apuntando a NULL.
.- Se llama a la funcion que controla el parseo y comprueba que los numeros cumplan con los requisitos que se nos piden. Si encuentra errores se sale.
.- Si sale todo bien, y estan metidos en la pila a, los numeros, entonces el programa decide en funcion de la cantidad de numeros que hay si llama a una funcion de ordenamiento o a otra. 

Parte 3: Ordenarlos.

.- El algoritmo general es sencillo. Es ir localizando el numero mas grande o mas pequeño de la pila a, 
donde estan sin ordenar, ponerlo en la cima de la pila y pasarlo a la otra pila.
Cuando hayamos acabado, en la pila los tendremos ordenados. Esto requiere muchos movimientos, es un algortimo 
correcto pero va a requerir muchos pasos, mas de los que el subject pide.
En la pila a, tenemos los numeros desordenados y desagrupados y para hacer mas eficiente el algoritmo vamos a 
hacer un paso inicial que es el de agrupar. Vamos a agrupar los mas pequeños y los mas grandes para que cuando
tengamos que llevar a la cima el mas grande o el mas pequeño, tengamos menos ordenes que ejecutar y el algoritmo 
sea mas eficiente, sera mas facil porque estaran mas cerca.
Para agrupar necesitamos saber que posicion ocuparia los numeros de la pila a, una vez que estviesen ordenados.
Este ha de ser el primer paso que hay que hacer para poder agrupar.
Esta funcion es "enumarate_index_nodes" en una pila de 500 numeros el numero 1 estaria en la posicion 1 y el 500 en la posicion 499.
Recorre todos los numeros y asigna a cada numero de la pila a, qué posicion ocuparía si estuviese ordenado.Para cada numero de la pila, los recorre desde el principio y chequea cuantos numeros son mas pequeños que ese.

.- Hasta 10 llamará a la funcion de ordenamiento sort_few_numbers, pasandole la direccion de memoria donde se encuentran las pilas (a y b).
. A partir de 10, se llama a la funcion enumerate_index_nodes (a) -> esta funcion lo que hace es recorrer la pila, comparar uno con todos y colocar una marca en una variable local pos_ordered (donde se coloca realmente es en index) colocandole la posicion que ocuparia si estuviese ordenado.
Ejemplo : 4 3 2 
posicion = 0 1 2 (real, desordenado)
Posicion si estuviesen ordenados = 2 1 0 (index)
.- Luego, para ser ordenados de forma eficiente necesitamos hallar la raiz cuadrada del tamaño de la pila.
Ejemplo: Si son 100, la raiz seria 10 y vamos a ir haciendo movimientos de 0 a 10, luego de 0 a 11, luego de 0 a 12 en funcion de los valores que pasemos a la pila b, asi hasta acabar la pila y dejarla vacia.
Los movimientos van a seguir una logica de orden que es la que resuelve la función Ksort1
.- Se llama a KSort1, que lo que hace es dos movimientos :
   Sabiendo las posiciones que comprenden la raiz cuadrada Coge el primer nodo/numero de la pila y si la posicion que le devuelve la variable index esta entre los valores de la raiz cuadrada (en el caso de 100, entre 0 y 10), lo pasa a la pila b y si no, lo rota y lo coloca debajo.
   Para que sea más optimo, hace una comparacion extra, si está entre los n numeros mas pequeños siendo n (lo controla la variable b_nodes que empieza en cero y se va incrementando en funcion de los numeros que vamos pasando) el numero de elementos en b, ademas de pasar el numero a la pila b, lo coloca al final. De esta forma se asegura que los mas pequeños esten al final de la pila.
.- Una vez finalizado el ksort, se llama a Ksort2, pasandole de nuevo como argumentos las direccion de memoria de las dos pilas.
Mientras la pila b no este vacia, en pos_max guardaremos el numero maximo llamando a la funcion que nos da su posición. 
En la variable end guardaremos cuantos numeros hay en la pila b, llamando a la función list_size.
En las variables distance_end guardaremos la distancia que hay entre la posicion final de la pila y la posicion del numero maximos.
En la variable Distance_start guardaremos el valor de la distancia que hay entre la posicion del mas grande y el principio de la pila, la posición cero.
Si la distancia del final es mayor o igual que la del principio , mientras la posicion del mas grande no haya alcanzado la posicion cero, significa que vamos a colocar el mayor en la posicion cero pasando los de arriba hacia abajo. En caso contrario pasaremos los de abajo hacia arriba hasta que llegue el mayor a la posición cero.

.- Una vez haya acabado, se libera el espacio de memoria de las pilas.
La pila a se destruye porque tiene los numeros y la pila b se destruye por buena educacion, no haría falta porque esta vacia, apunta a NULL, pero esta bien hacerlo. 
__¿Porqué el algoritmpo KSORT es mas eficiente?__

Si vamos a buscar un numero unico, ejemplo el 1, depende de donde esté voy a gastar muchos movimientos para moverlo y pasarlo, por lo tanto para grandes cantidades de numeros no es eficiente. Sin embargo si en lugar de uno, busco unos cuentos de un grupo especifico, entonces me van a valer mas de 1 uno. Si tengo  numero sy busco los 10 primeros, me sirve encontrar el 1, el 2, el 3 etc....pero si solo busco primero el 1 , luego el que este en la posicion 2, luego el que este enla posicion 3 tardo mas y gastos movimientos.


**Funciones de verificacion**

1.- __static int parse_argv(char *argv, t_stack_list **stack)__

Por cada argv, verificamos si el numero es correcto y lo metemos en la pila. Esta funcion comprueba que  sean numeros enteros, que no esten repetidos, los pasa de char a int, los mete dentro de un nodo de la pila y libera la reserva de memoria.
Si nos pasan numeros enteros es muy secillo, solo hay que convertirlos a numero pero tenemos que contemplar que nos pasen un argv de mas de un numero, por lo que necesitamos separlos antes de meterlos en la pila.
Necesitamos interpretar los argumentos y meterlos en la pila, asi que a para cada argv usamos el ft_split para separar por espacios cada numero.
Cada parte le hacemos un atoi y si va bien le metemos en la pila.

Nos declaramos una variable ** split para meter el resultado de trocear el array de numeros que reciba.
LLamo a la funcion ft_split pasandole el argv y el delimitador, el espacio.
Si el split falla, me salgo.
Si no inicializo un index a cero y bucle para recorrer el array.
Mientras cada posicion del array recibido sea distinto de NULL, el index va aumentando uno pero en medio.
inicializamos una varible llamada num donde meteremos el resultado de llamar a su_atoi, pasandole lo que hay en cada posicion del split y el valor de atoi_error parar pasar a int cada numero.
Si hay un error en el numero o esta repetido, se sale.
En caso contrario llama a list_append_front para meter el numero en cada nodo.
Si falla, llama a la funcion free_split que se encarga de liberar lo reservado para lo que ha fallado y para lo que no ha fallado anteriormente que tambien hay que liberarlo.
Si no falla sigue hasta que no haya nada mas y libera la reserva para la variable split y retorna 1, retorna que si, esta todo ok.

.- __static int is_num_repeated(t_stack_list *a, int num)__

Esta funcion recorre la pila y mientras no este vacia, si el numero de la pila es igual al numero que recibe retorna 1, que si esta repetido.
Si no sigue al siguiente.
Si no se sale antes, es que no esta repetido.

.- __static void free_split(char **split)__
Esta funcion recorre el array de numeros hasta que no haya nada y va liberando posicion a posicion l memoria reservada.
Cuando acaba libera tambien la reserva de memoria del array.
.- __int su_atoi (const char *str, int *p_error)__

Declaramos un long para poder comprobar si me pasan un numero int que sobrepase el max, tener espacio para que quepa y poder generar un error.
Antes de convertir el char numero en entero, comprueba si hay algun caracter raro y se lo salta, comprueba si es positivo o negativo, lo convierte a int, en caso que falle se sale, en caso de que sea negativo lo convierte en positivo y comprueba que el valor entre entre el maximo y el minimo de enteros permitidos.
Si llega hasta el final, retorna el valor.

.- __long convert_to_int (const char *str, int *p_error)__

Primero comprobamos que la cadena no esté vacia.
Inizializamos long value a cero y recorremos la cadena recibida.Mientras cada digito este entre el char 0 y el char 9 y ademas el valor sea menor o igual que el máximo + 1, se convierte a int. Si nos hemos salido antes de terminar el bucle es porque nos hemos encontrado un caracter que no es un digito o nos hemos pasado del numero maximo.

	Entonces si no ha llegado al final p_error retornará 1 en caso contrario 0 y retornará el valor del numero.

	MAX + 1
  Yo sumo 1 y sin embargo resto.
  Si un entero son 4 bytes, que son 32 bits, 31 bits es el numero , el ultimo bit es el signo.
  La mitad de los numeros son negativos y la otra mitad son positivos.
  La mitad son a bit de 1 y la mitad es el 0.
  Si tengo 1000 numeros, 999 seran positivos y -1000 negativos, por lo tanto los positivos han de ser 999 + 1. 

__t_stack_list *list_append_front (t_stack_list **numbers, long number)__

Hay que crear dos variables una new node * y otra last node * para crear el nodo y añadirlo por delante.
Si falla se retorna error y si no hay ningun nodo aun, el que nos pasan será el primero.
En caso contrario, en last_node se meterá el numero y bucle para recorrer toda la lista hasta el final y los voy añadiendo. Retorna la direccion donde empieza la lista de numeros.

__void sort_few_numbers (t_stack_list **a,t_stack_list **b)__
Si los numeros recibidos son menos de 10, nuestro sistema de ordenamiento consistirá en buscar el numero mas pequeño y moverlo de la pila a a la b, poniendo los mas pequeños abajo de la pila b.
Nos podemos encontrar que la pila a pase una serie de numeros a la pila b pero de pronto en la propia pila a esten ordenados o esten ordenados con un corte, por eso el programa ha de contemplar este caso.
Hace un bucle recorriendo la pila a y mientras la pila no este vacia o no este ordenada, pasa de uno a uno los numeros mas pequeños a la pila b.
Pero se puede salir del bucle porque la pila a ya este ordenada o con un corte, en ese caso llamaria otra vez a la funcion mov_min_number pasandole como argumento la pila a y en caso de que haya un corte (si no lo hay no hará nada), lo ordena.
Una vez hecho esto, ya puede pasar todos los numeros de la pila b a la a.

__void move_min_number(t_stack_list **a)__
ESta funcion se encarga de buscar la posicion del numero mas pequeño, lo sube arriba.
LO hará en funcion de la distancia que haya entre el su posicion el principio o el final.

Si esta más cerca de la posicion cero, lo hará poniendo el primero al final (ra) y si esta mas cerca del final, lo hara poniendo el final en el principio (rra).

__int search_sortest_number (t_stack_list *stack)__

Para encontrar la posicion del mas pequeño, necesitamos saber el tamaño de la pila. Para eso llamamos a list_size que nos dice cuantos numeros hay en la pila.
Necesitamos un t_stack_list *node que inicializaremos con el primer nodo de la pila.
Un index que comienza en cero y una variable int min, dodne guardaremos el valor del numero de cada nodo, inicializandolo en el primer numero.
Bucle para recorrer toda la pila, mientras el index no alcance size, si el numero del nodo es menor al primero, entonces en min meteremos ese nuevo numero y en pos_min, la posicion que ns marque index.
Y luego pasaremos al siguiente nodo e incrementaremos el index.
Cuando os salgamos del bucle, retornaremos pos_min que nos dirá en que posicon esta el número más pequeño.

__int is_sorted(t_stack_list *stack)__

Para que este ordenado pueden pasar dos cosas, que este ordenados entre si y lleguen hasta el final metiendose en el primer bucle.
Pero si no se sale por eso, puede que haya un corte, que es lo que hace al segundo bucle, tengo que comprobar que he llegado al final y si es porque hay mas de un corte, me salgo.
Y ademas, si he llegado se tiene que cumplir la segunda condicion que el ultimo numero no sea mayor que el del inicio.

Ejemplos: 50 40, estaria ordenado porque con un solo movimiento rra lo ordenaria -> 1 corte
          50 40 45 estaria ordenado porque con un solo movimiento ra, lo ordenaria -> 1 corte
          60 50 40 no está ordenado porque por muchos movimientos que se hagan habria mas de un corte.
Por eso para retornar algo diferente de cero (1 por ejemplo) debe cumplir as dos condiciones, que haya acabado y que el ultimo sea menor al primero.
Node == NULL signific que ha llegado al final porque habia un corte y la segunda condicion, la varibale number contiene el ultimo número de la pila y en number. 
Ejemplo de bien  = 10 20 1 2 3, esta ordenado con un corte
ejemplo de mal = 10 20, 1 2 50. 10 y 20 estan ordenados y 1 2 50 tambien, hay 1 corte pero si 50 es mas grande que 10, estaras haciendo rotaciones en bucle sin ser capaz de ordenarlo.
por eso es necesario las dos condiciones, que haya llegado al final y que el ultimo de lso numeros sea menor que el primero.

__void enumerate_index_nodes(t_stack_list *stack)__

Esta función recorrerá la lista para cada nodo, la pila completa, buscando la posición que cada nodo ocuparia si estuviese ordenado en orden creciente y lo guardará en una variable llamada index de la estructura pero que controlará la variable local pos_ordered 

Por eso hay dos bucles de principio a fin, porque comparará cada uno de los numeros con todos e ira viendo si son mas pequeños que el y en funcion de eso incrementara pos_ordered.

Ejemplo : 5 3 1 2 

Declaramos una variable iterator que es la que va a recorrer de principio a fin cada nodo.
Iterator empieza apuntando a 5 a stack.
Declaramos una nueva variable auxiliar que dentro de este bucle tambien apuntará a stack, a el 5.
Pos_ordered comienza en cero.
Bucle, dentro de otro cucle, recorriendo aux hasta el final.
Si el número (5) es mas pequeño que el numero de iterator (5). pos_ordered se incrementa.
y aux pasa al siguiente, el 3.
Como el 3 es mas pequeño que el 5 pos_ordered incrementa, POR AHORA el index de 5 es 1 porque ya hay un numero mas pequeño que el.
y pasa al siguiente 1, que tambien es mas pequeño que 5 por lo que pos_ordered incrementa, POR AHORA el index de 5 es 2
y pasa al siguiente que es 2, que tambien es mas pequeño que 5 asi que pos_ordered aumenta.
Como hemos llegado al final, se sale del bucle y entonces, ya sabemos que el index de 5 es el 3, EN ORDEN CRECIENTE.
y pasamos al siguiente nodo de la pila (iterator) para volver a compararlo en el bucle de dentro con todos.
asi hasta que hayamos comparado todos con todos y en el index marcado la posicion de toda la pila en orden creciente.
__int sqrt_num(int number)__

* Si un numero es menor que cuatro ( Raiz cuadrada de 4 es 2), por lo tanto numero inferior a 4, su raiz cuadrada es 1, retornamos 1.
* Indice empieza en 1.
* Bucle para hallar la raiz cuadrada de cualquier número.
  Mientras la multiplicacion de i por si mismo sea menor que el numero que queremso hallar su raiz cuadra...i sigue creciendo.
  Ejemplo: 25 
  2 * 2 = 4 y es menor que 25
  3 * 3 = 9 es menor que 25
  4 * 4 = 16 y es menor que 25
  5 * 5 = 25 y ya no es menor que 25 por lo tanto la raiz cuadra de 25 es 5.

__K_sort1(t_stack_list **a, t_stack_list **b)__

 El reto que se nos plantea es pasar de la pila a a la pila b los numeros, los mas organizados posibles, abajo los mas pequeños, arriba los más grandes.
 Para ello contamos con el indice previamente localizado con la funcion enumarates_index_nodes que nos dice que posicion 
 tendrian si estuviesen organizado.
 Ejemplo: 100 numeros. Posiciones del 0 a 100 en index. 
 Si comparamos ese indice de 1 en 1, se necesitan muchas operaciones ra para pasarlo, funciona pero es ineficiente.
 Si lo comparamos con un solo grupo de 100, pasaria tal cual y no estaria organizado.
 ¿ Como podemos pasar los numeros de a a b lo más organizados posibles y ser eficientes? 
 Ejemplo : 100 numeros si hacemos muchos grupos de pocos elementos necesitamos hacer muchos ra.
                       si hacemos poco grupos de muchso elementos -> pasan menos organizados  
 La forma mas equilibrada para conseguir un numero de grupo óptimo y un número de elementos optimo es la raiz cuadrada.
 Ahora ya podemos aplicar el algoritmo que consiste comparar el index con la raiz cuadrada + el numero de elementos que va pasando de la pila a a la b.
 Mientras la pila a no este vacia si el index es más pequeño o igual que la raiz cuadra + el valor que tenga b_nodes que es la variable que controla el
 numero de elementos que se van asando a la pila, sabemos que esta entre los más pequeños de ese grupo.
 Y en caso de encontrarse el mas pequeño, ademas de pasarlo lo pondriamos abajo del todo, haciendo un rb.
 Si no es el mas pequeño y no esta entre los mas pequeños, entonces ra. 

  * if((*a)->index <= b_nodes) // optimizacion, de ser el mas pequeño -> pa(a, b)-> rb(b)-> b_nodes++;
  * else if((*a)->index <= (b_nodes + sqrt)) // algoritmo -> pa(a, b) -> b_nodes++;
  * Si es de lso grandes -> ra(a);

___void k_sort2 (t_stack_list **a, t_stack_list **b)__

Como estan en la pila b organizados de forma que los numeros estan a pocos rb o rrb de distancia entre si y en general los 
mas grandes estan en la parte superior y los mas pequeños en la parte inferior. Ahora, buscanbdo la posicion del mas grande y pasandolo 
a la pila a, ordenamos de forma creciente la pila b en a y de forma eficiente, cumpliendo el objetivo del proyecto.
Buscamos la posicion del mas grande llamando a la funcion search_max_num.
Llamamos a la funcion move_node_to_top para ver si lo subimos por arriba o por abajo en funcion de la distancia que haya de ese index con la posicion cero o con la ultima posición.
Luego hacemos una operacion rb o una operacion ra.

__int search_max_num (t_stack_list *stack)__

  Esta busca la posicion del mas grande. Tenemos el index de la posicion que ocuparia cada elemento si estuviesen ordenado.
  Sabiendo el numero de elementos que tiene llamando a la funcion list_size y declarandonos una variable pos_max que empezara en cero.
  Bucle para recorrer la pila hasta el final y si el indice del elemento en cuestion es igual que (size -1) -> pos del ultimo elemento
  es que lo he encontrado, en caso contrario itero y pos_max va creciendo para seguir mirando el siguiente elemento. 

__void list_stack_push.c
__static void	move_top_node(t_stack_list	**from, t_stack_list	**to)__
  Hacemos una funcion que mueve el nodo completo, junto con el numero de dentro desde el top de una fila a otra pila. 
  Chequeamos si esta vacia, si no, el primer nodo es el desde donde y vamos cambiando los punteros.
  From es el primer nodo de la pila a
  to es el priemr nodo del segundo carro.
  Queremos coger el primer nodo de la pila a y moverlo a la pila b o viceversa.
  ¿ que tenemos que hacer ? desengancharlo del segundo nodo de la pila a la que esta enganchada por su nodo.
  
  first_node = *from;
	*from = first_node->next; ahora sujeta el siguiente, o sea el segundo
	first_node->next = *to; ahora lo encadenamos al primer carro de la otra fila
	*to = first_node; y uan vez que esta ese nodo ahi, to deja de sujetar el de antes y sujeta el que acabo de pasar.
__void pa (t_stack_list **a y t_stack_list **b)__

Coje el primer nodo de la pila a y lo pongo en b.
Para ello se declara un long num, donde vamos a guardar el contenido del numero llamando a list_stack_pop (a)
Lo ponemos en b llamando a la funcion list_stack_push (b)
Escribimos la orden pa si es necesario, si la booleana es 1, asi indicamos si hay que escribir o no en funcion de cual es, si es el push_swap o es el checker.

__void pb(t_stack_list **b, t_stack_list **a)__

Coje el primer nodo de la pila b y lo pongo en a.
Para ello se declara un long num, donde vamos a guardar el contenido del numero llamando a list_stack_pop (b)
Lo ponemos en b llamando a la funcion list_stack_push (a)
Escribimos la orden pb, escribimos la orden pa si es necesario, si la booleana es 1, asi indicamos si hay que escribir o no en funcion de cual es, si es el push_swap o es el checker.

__static void	rotate (t_stack_list **stack)__
  Esta funcion mueve el primer nodo de la lista al final y esto va a afectar a tres nodos, el primero, el segundo y el ultimo.
  * El primero porque ya no va a apuntar al segundo sino a Null
  * El segundo porque tiene que ser guardado en stack-> que es un doble puntero.
  * El ultimo porque tiene que apuntar al primero.
    asi que nos declaramos esas tres variables y las inicializamos 

  * Primer nodo = *stack
  * Segundo nodo = a donde apuntaba el primero. Se queda igual en un principio.
  * Ultimo nodo = comenzando desde el segundo nodo (el primero no es necesario porque va a rotar)
                  Bucle hasta el final para localizarlo.
    Y cuando ya tenemos los tres inicializados es cuando hacemos los movimientos.
  *  Ahora stack apunta al segundo 
  *  El ultimo apunta el primero
  *  El siguiente del primero es NULL.

    __static void	rotate_reverse (t_stack_list **stack)__
   Esta funcion mueve el ultimo nodo de la lista al principio y esto va a afectar a tres nodos, el primero, el penultimo y el ultimo.
   * El primero se iniciliza en el valor de *stack
   * el penúltimo lo localizamos recorriendo desde el segundo hasta el que el ultimo apunte a NULL.
   * Y una vez localizado el ultimo sera donde apunte el penultimo.
   y ahora ya podemos mover 
   * Stack tendra el valor de donde este el ultimo
   * El siguiente del penultimo apun tara a NULL
   * El siguiente del último ya no apuntará a NULL sino al primero.

   __static void	swap(t_stack_list *stack)__
  Mueve los nodos y los punteros de unos a otros.
  Si la pila está vacia o solo hay un número, no se puede intercambiar nada.
  Necesitamos dos variables que representen dos nodos.
  Y empiezan los punteros.

  * First node tiene el valor de stack, de la dirección de memoria dle primer nodo.
  * segundo nodo es igual a donde apunta el primero.
  * El next del primero ahora es el next del segundo.
  * El next del segundo ahora es el primero.
  * El stack es igual al segundo.
  	