**Explanation Get_net_line**

Funcion que recibe un file descriptor y devuelve la siguiente linea de ese fd.
Lo hace leyendo bloques de bytes del disco, en funcion de un BUFFER_SIZE y va devolviendo las lineas 
cuando se encuentra un salto de linea o el final del fichero.

1.- __char	*get_next_line(int fd)__

. Declaramos una variable estatica char *block-> que recogera lo que se vaya leyendo
. Declaramos uan variable char *line-> que recogera las lineas.
. Si al leer el fd falla, se sale y retorna NULL
. Si block == NULL algo que ocurrira la primera vez, se reserva 1 byte de memoria y si no falla se mete el '\0'.
. En block meto el resultado de leer todos los bloques que encuentre hasta el el que tiene el salto de linea 
  (incluyendo lo que haya despues del salto de linea hasta el total de bytes que me marca BUFFER SIZE)
. Si BUFFER_SIZE es 10 y encuentra el \n en el 25, block tendra lo que haya hasta el 30.
. Si falla el malloc de block se sale
. Si no, en line se mete la linea extraida llamando a la funcion ft_line,
. Ahora en block se metera lo que hay despues de la linea que se acaba de extraer, llamando a la funcion ft_skip_to_next_line,
. Retorna la linea.

2. __char	*ft_read(int fd, char *block)__

Recibe un bloque de memoria y el fd, lee y devuelve la posicion donde esta el bloque leido. 

. Declaramos un buffer con el tamaño de BUFFER_SIZE + 1
. Declaramos una variable int donde meteremos los bytes leidos.
. MIentras no falle la reserva de memoria de block y no se haya encontrado el \n
. En bytes_read metemos la cantidad de bytes leidos.
. Si bytes_read es cero, es que hemos llegado al final y se retorna el bloque.
. Si bytes_read es -1 es que ha fallado la lectura, entonces liberamos la memoria de block y retirnamos NULL.
. En buffer en la posicion que marque bytes_read metemso el '\0'.
. En block, adjunto lo leido a lo que haya en block llamando a la funcion ft_strjoin.
. Retorno el block.
	
3. __char	*ft_line(char *block)__
Recibe el bloue, bisca \n y retorna la linea.

. Declaramos un char *end_of_line, dodne meteremos la posicion de donde esta el \n.
. Declaramos una variable char *ln, donde meteremos un duplicado de lo que haya en el bloque.
. Declaramos un size_t para meter la cantidad de bytes que hay que duplicar cuando se encuentre el '\0'.
. Si falla la reserva de memoria de block o el bloque esta vacio, retornamos NULL.
. En end_of_line se mete la posicion donde está el \n.
. Si end_of_line es == NULL significa que no ha encontrado el \n.
  Entonces en ln habra que meter todo el bloque llamando a la funcion ft_strdup.
. line_size nos dira el numero que hay desde el \n a el comienzo de block.
  Ejemplo : HOLA\n -> la H esta en 1000 y el \n esta en el 1004 y la funcion strchr devuelve el tamaño hasta el \n + 1(el siguiente).
            en el ejemplo, seria 4 + 1 = 5.
. En ln duplicaremos la linea llamando a la función ft_strndup.
. Retornamos la linea.
	
4. __char	*ft_skip_to_next_line(char *block)__
Recibe el bloque y retorna la donde empieza la siguiente linea.

. Declaramos una variable de tipo char * end_of_line metemso la posicon donde esta el \n.
. Declaramos una variable de tipo char * next_line metemos la copia desde el \n hasta el '\0'.
. Si falla la reserva de memoria de block, retorna NULL.
. end_of_line se mete la posicion dode se encuentra \n, llamando a ft_strchr.
. Si no encuentra el \n, libera la memoria de block y retorna NULL.
. en next_line metemos una copia desde el \n hasta el '\0'.
. Liberamos block y retornamos la siguiente linea.

5. __char	*ft_strndup(char *str, size_t len)__
Copia de una string los bytes que le indique la variable len.

. Si en str no hay nada que duplicar, se sale.
. En la variable de tipo char * dup hacemos un malloc de los bytes que marque la variable len + 1 para el '\0'.
. Si falla la reserva , retornas NULL.
. El contador empieza en cero.
. Mientrás el contador no alcance la cantidad limite de bytes que marca la variable len
  en cada posicion de la variable dup se copia lo qu ehaya en cada posicion de str.
  el contador itera y cuando se sale 
. En dup se añade el '\0'.
. SE retorna dup.

6. __char	*ft_strdup(char *s1)__
Duplica una string entera.
. Retorna lo que le devuelva la llamada a la función ft_strndup, pasandole un strlen de la string y la string.

7. __char	*ft_strjoin(char *str1, char *str2)__

Recibe dos strings, las concatena dos strings y devuelve una nueva con las dos concatenadas..

. Declaramos dos posiciones para cada una de las 2 strings que recibimos.
. Declaramos una varibale tipo char * join donde guardaremos la concanetacion de las dos strings.
. Si la str2 no tiene nada, se retorna solo la str1.
. Si no, en join se reserva memoria de el tamaño de bytes de str1 y str2 + 1 '\0'.
. Si falla la reserva se libera la memoria de str1, se retorna NULL.
. pos empieza a cero y se recorre str1 hasta el final de la str1.
  Se mete en cada posicion de join lo que hay en str1.
  pos itera.
. Cuando se sale, pos2 se inicializa a cero.
. Se recorre str2 y en join en la posicion que haya lo que haya en str2
  itera pos y pos2.
. Cuando se sale en la posicion de join[pos] se pone el '\0'.
. Libera la reserva de str1.
. Retorna join.

8. __char	*ft_strchr(char *str, char c)__

Recibe un char y una string y busca ese carcater en al string y retorna su posicion, donde se encuentra ese char.

. Si string esta vacia , retorna NULL.
. Se inicializa pos con el valor de str.
. Se recorre pos hasta el final 
  Si se encuentra el caracter se retorna la posicion siguiente de donde esta el char que se busca.
  Esto se usa para encontrar la posicion siguiente al \n y asi usarlo para seguir leyendo a aprtir del salto de 
  linea e ir extrayendo linea a linea.
 . Si no lo encuentra itera pos, al siguiente caracter.
 .- Si no lo encuentra al salirse del bucle, retorna NULL.

9. __size_t	ft_strlen(char *str)__

Recibe una string y retorna su tamaño.
. Si la string esta vacia, se sale.
. Bucle para recorrer la string posición a posición hasta el final de la string, se itera la posicion y cuando 
  acaba, retorna la posicion y eso nso dice cuando mide la string.

