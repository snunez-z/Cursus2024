
**Explicacion del ejercicio de examen ft_print**
Consiste en reproducir el comportamiento de la funcion "printf" pero solo recogiendo lso dtaos de un entero decimal "d", un hexagesimal "x" y una string "s".

¿ Como lo hace ?


1. __A nivel general__
La funcion ft_printf es una funcion que tiene que recibe el formato de lo que quieres escribir ( texto + marcas que vienen prefijadas por % que es lo que vamos a sustituir por cosas)y luego los parametros necesarios para sustituir esas cosas.
El numero de % algo es indeterminado, el numero de parametros y el tipo de parametros es indeterminado.
No se puede dar un tipo exacto, un tipo indeterminado y lo que es indeterminado se especifica con ...Por eso recibe algo que es fijo que es un char * format y a partir de ahi, ... que lo que no sabemos, dependen de las marcas.

Estos parametros se consiguen con los va_list (modulo que se inicializa con va_start y que finaliza con va_end.)
A va_start hay que pasarle el ultimo parametro conocido que es el formato. 
Una vez que sabemos de que tipo es lo siguiente a format llamamaos a va_arg pasandole el siguiente argumento y un int, con una variable que va a recoger el numero de caracteres que va leyendo. 

2. __ft_printf (conts char * format, ...)__

* Declaramos una variable de tipo int para recoger el numero de caracteres que va leyendo la funcion.
* Inicializamos va_arg con el next_arg -> siguiente argumento.
* Inicializamos va_start pasandole el siguiente argumento y el formato.
* se recorre format hasta el final y va avanzando hasta encontrarse un %.
* Si hay un % y el siguiente es una 's' o una 'd' o una 'x', avanza 1 y dependiendo de lo que haya detras hace una cosa u otra:
  - Si es una 's' llama a put_string que recibirá como argumento lo que le devuelva va_arg (que va a ser el siguiente argumento y el tipo del argumento, en este caso un char *), la longitud del formato que lo recoge la variable de tipo int length.
  - Si es una 'd' se llama a put_digit que recibira los que le devuelva arg (el siguiente argumento y el tipo del argumento que en este caso es un int), la base que es 10, la longitud del numero que lo recoge la variable de tipo int length.
  - Si es un 'x' se llama se llama a put_digit que recibira los que le devuelva arg (el siguiente argumento y el tipo del argumento que en este caso es un int), la base que es 16, la longitud del numero que lo recoge la variable de tipo int length.

* En caso de que sea algo diferente a una de estas tres opciones, se escribe lo que hay y lenght avanza.
* Cuando llega al final de format, se llama a va_end pasandole el ultimo argumento.
* El programa retorna la longitud, el número de caracteres que hay en length.
3. __put_string(char *string, int *lenght)__

   Corner case = Si la string lo que recibe es null, entonces el valor de la string será ese "(null)".
   Funcion que recorre una string hasta el final y va escribiendo cada carácter y avanzando length que recoje el número de caracteres que tiene la string.
   No retorna nada.
4. __put_digit (long long int number, int base, int *length)__
   . Recibe un longo long int para asegurarse que le cabe el numero negativo mas grande. 
   	 Ejemplo : 
     si los numeros estarian entre el 0 y el 50. El numero maximo positivo seria el 49 y el negativo el -50, por lo tanto ese -50 no le cabria a la hora de pasarlo y convertirlo en positivo.
    number = number * -1 lo convierte a positivo, pero si el maximo positivo es el 49, el -50 no podria entrar aqui.
   . Con un long long,  se evita que pasando el maximo negativo, nos quepa a la hora de   convertirlo a positivo.

      Se declara un char * hexadecimal donde metemos los caracteres que manejan los hexadecimales como tabla de conversion. 
	  . Si el numero es negativo se convierte en positivo
	  . Se escribe en pantalla un -
	  . y aumenta uno length.
	  No retorna nada.
	  
   