## Checker

El checker consiste en dos partes:
1.- Comprobar si lo se recibe está bien. Para eso hace lo mismo que el push_swap, llamar a las funciones de comprobación de números y conversión a ints. 
2.- Llamar a la función read_result_push_swap, que va a leer los resultados del push_swap y va a hacer lo mismo que ha hecho el push_swap para ver si está bien, si está ordenado.
Si está ordenado escribirá en pantalla OK y si encuentra un error escribirá KO.

__read_result_push_swap__ 

Creamos una variable buffer pequeño de 10 bytes, porque las ordenes ocupan poco.
UN int donde recogeremso el resultado de verificacion de lectura.

Y bucle para recorrer linea a linea el resultado del push_swap, si la lectura no falla entonces ejectuamos el comando uno a uno llamando a la funcion execute_one_command y asi hasta el final. Hasta que ya no haya nada mas que leer.
	
__read_line (int fd, char *buffer, size_t bytes_max)__
	
  Se lee la linea char a char de cada fd.
  Mientras haya algo que leer y el index no alcance el maximo de bytes y el carcater no sea el final de la linea, del salto de linea, se escribe y se pasa a la siguiente. 
  Cuando se sale se pone el barra/0.
  Si no hay nada que leer o el indez es mas grande o igua que el maximo, se sale.
	
 __void	execute_one_command(char *comd, t_stack_list **a, t_stack_list **b)__
   
   Comparar las ordenes y en funcion de ellos, se hace una operación u otra.
	 
  DEspues de eso, si esta ordenado OK y si no KO.
  Liberar las pilas. 