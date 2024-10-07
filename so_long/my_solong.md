## My Solong explicacion.

El Solong es un proyecto de modulos y como en todos los modulos hay funciones de creacion, funciones de destruccion 
y en medio funciones que hacen cosas, de operaciones.Está el modulo del mapa, el módulo de las imagenes, el modulo de
la fuente (caracteres) y el módulo del juego.
El principal, el que engloba al resto es el **" game"**.**"game"** cuando se crea . crea a su vez el mapa. las imagenes
y la fuente. Y al destruirse hace lo mismo pero en orden inverso.

Pasos:

* **Carpeta minilib:** Descargo la minilibx que es tambien un modulo y voy a usar sus funciones dentro de mi proyecto segun las necesite.
* **Carpeta images:** He buscado las imagenes en google (manzana, gameover, pared ...), son imagenes .xpm, formato grafico que usa linux. 
Este formato lo soporta la minilibx por eso los hemos elegido.Linux (GIMP), es una especie de photoshop que abres imagenes en un formato 
y lo puedes convertir en otro.
* **Carpeta font** Para escribir el numero de movimientos hemos cogido una imagen de cada caracter ascii que vamos a usar. Si usamos la 
funcion mlx_string_put para ello, la letra sale muy pequeña, asi que he usado imagenes con el tamaño 32 * 32 pixeles y asi poder 
hacer la letra mas grande.
* **Carpeta obj** Estan todos los ficheros .o.
* **Carpeta lib** EStan los ficheros .a.
* **Carpeta libft y ftprintf** para usarlo a lo largo del proyecto.
* **Carpeta inc** con los .h.
* **Carpeta maps** con los mapas de referencia para probar el funcionamiento del programa.
* **Carpeta src** todas las funciones que usa el programa .c.

**Modulos**

El proyecto lo que hace es leer un mapa (modulo del mapa y las funcioens correspondientes) pero antes de llegar ahí, necesita leer el archivo
linea a linea (modulo dstr), 
guardar todas las lineas en una lista (modulo list.c) y la lista de dstr la guardamos en (modulo map.c y las funciones correspondientes).
Luego hay que pintar ese mapa y para ello vamos a usar la minilibx.
Resto de funciones son de verificación ( modulo map) excepto la verificacion de si el tamaño rebasa la pantalla o no.
(El modulo map) no asume que vas a pintar en una pantalla, podrias pintar en una web, en una terminal de consola, se podria jugar en pantalla,
 el modulo map serviria, está preparado para ello.Por lo tanto es el (modulo game.c) quien lo verifica, porque es a quien le corresponde.


1.**_DSTR_**: No sabemos el ancho del mapa, cuantas columnas tenemos que leer y guardar.Proporciona funciones para manejar buffers de caracteres
 que crecerán automaticamente.Como no sabemos la longitud que tiene cada linea, necesitamos una estructura /modulo que nos permita añadir caracteres 
 a un buffer y ese buffer crezca si es necesario. BUffer_chunk_size.
  1. **t_dstr	*dstr_create(void)->reserva memoria estructura y buffer.** Crear instancia para la estructura y para el buffer.
  2. **void	dstr_destroy(t_dstr *dstr)** Liberar memoria en sentido inverso
  3. **char	dstr_char_at(t_dstr *dstr, size_t pos, char ch)**
     Esta funcion hace se llama para hacer tres cosas. Simplemente recorrer el mapa donde tenemos que saber que hay en cada posicion y asi poder 
     pintarlo. Cuando se mueve el jugador para meter lo que habia antes de ese movimiento. Guardar lo que habia antes y cambiar.
     ejemplo = 1EP001 -> previous = E-> ch ->  dstr->buffer[pos]= P.

  4. **int	dstr_append_char(t_dstr *dstr, char ch)**
       LLamamos a esta funcion cuando necesitamos añadir en el buffer todos los caracteres del mapa. Secuencia leo y guardo en funcion del buffer_size.
       \0 es un convenio para lso arrays, que tambien se usa con * para poder localizar el final de un array de chars. En este caso no lo necesitamos 
       porque tenemos un campo de la estructura buffer_index que ya nos marca el final, nos dice cuantos hay. 
  5. **size_t	dstr_length(t_dstr *dstr)**
     Lo usamos para saber cuantos caracteres comprobemos que el mapa es rentangualar.

2. **_LIST_** : Lo necesitamos porque no sabemos cuanta profundidad tiene el mapa, las filas que tenemos que leer. En cada nodo de la lista vamos 
a meter un dstr, sumamos las listas para poder añadir tantas como necesitemos.
  1. **static t_list	*create_node(void *data)**
     Forma parte de list append, es estatica y la llama list_append. solo reserva memoria e inicializa un nodo.
  2. **t_list	*list_append(t_list *list, t_dstr *data)**
     Hay dos casos, que sea el primer nodo por lo tanto apuntara a NULL y retornara ese primer nodo.
     Que sea a partir del nodo, que el last_node apuntara a null, pero al añadir, sera el siguiente el que apunte a NULL.
  3. **void	list_destroy(t_list *list)**
     Liberar el contenido y el contenedor.
  4. **size_t	list_size(t_list *list)**
     Lo vamos a usar para saber cuantas lineas tiene un mapa, que seran tantos como nodos.
  5. **t_dstr	*list_get(t_list *list, size_t pos)**
     La usamos para pedir lineas y asi saber su contenido. Ejemplo->Mover un jugador que estara en al posicion x de la linea y lo vamos a mover 
     a otra posicion y queremos saber que hay,un 0, una salida etc.... 
3. **Modulos del mapa**

_Estructura s_map_
* *rows = una lista que contiene cada línea (fila) del mapa
*  weigth = el ancho del mapa (valor máximo de X)
*  Height = la altura del mapa (valor máximo de Y)
*  player_x = posición X actual del jugador
*  player_y =  posición Y actual del jugador
*  at_player = qué había en la celda del jugador actual antes de moverse a esa celda.
              Esto es necesario para saber si la celda contenía comida (en cuyo caso, la comida debe ser "comida") o la salida (en cuyo caso, la 
              salida debe ser restaurada cuando el usuario se aleja de la celda).
* food_left = cuántas celdas de comida quedan por comer.

__Estructura s_map_loop_ 

* t_map	*map = direccion de memoria del mapa
* int		x = posicion x
* int		y = posicion y
* char	ch = contenido de la celda
* void	*data = direccion de memoria a un dato que puedo necesitar cuando sea llamado
3. **_MAP_READ_**
   Hay que leer el mapa, y lo tengo que hacer linea a linea y eso es una lista de lineas.
   Mientras la linea sea leible y no este vacia- que haya \n al final va añadiendo lineas a la lista.
   si falla al añadir, destruye y se sale, pero si falla al leer la linea tambien destruye y se sale.
   Si no falla nada, retorna la lista.
  
  1. **t_map	*map_read(const char *file_name)**
    Abre el fichero y te retorna el fd, retorna error si no existe o no tienes permisos.
    Reserva memoria para la estructura t_map, mete dentro de la lista rows la lectura de read_file, cierra el fichero y verifica que este todo bien. 
  2. **static t_list	*read_file(int fd)**
    Tengo la lista con cada una de las lineas pero voy a leer linea a linea.
    Inicialmente apunta a NULL porque es la primera
  3. **static t_dstr	*read_line(int fd)**
    Lee una linea y devuelve el * a dstr, que es una linea.
  4. **static int	read_line_into_buffer(int fd, t_dstr *line)**
    Es llamada por read_line y lee y añade carcater a carcater siempre que no
  5. **static int	verify_map(t_map *map)**
    Verifica que el mapa sea rectangular, que este rodeado de pared, que haya al menos 1 comida, un solo jugador y una sola comida y que el camino 
    sea valido, que sea posible el juego.
   
4. **_MAP_VERIFICATIONS_**

__Estructura s_map_loop_ 
*  int		exit_count = numero de salidas
*  int		player_count = numero de jugaroes

  1. **int	map_verify_square(t_map *map)**
    Se que es rectangular si las medidas del primer nodo ocinciden con el resto de nodosasi que lo que voy a hacer es comparar.
    Verifico que el mapa este bien.
    compruebo que haya de ancho y de alto al menos 3 para poder jugar. Dos paredes y un camino.
    Cojo la longitud del primer nodo, declaro un index a 1 para comparar el primero en la posicion cero con el segundo en la posicion 1 y si no son 
    iguales, me salgo y si son iguales sigo comparando hasta el final.
     
  2. **int	map_verify_items(t_map *map)**
     Inicializo la salida y el jugador a cero y llamo a la funcion map_loop para recorrer el mapa y le paso como argumentos el mapa, la funcion 
     count function (que cuenta cuantos items de cada hay y el puntero a la estructura).
     Con el resultado, especifico:
     . Si no hay al menos una comida y no hay solo un jugador y una salida, error, me salgo.
     en caso contrario, esta ok.
  3. **static	int	count_function(t_map_loop *map_loop)**
  Cuenta una celda y se le llamara cuantas veces se necesite hasta completar todas las celdas del mapa.
  Si me encuentro un jugador , anoto su posicion y añado uno al contador. Y pongo a cero lo que habia antes.
  Si me encuentro una salida cuento y añado uno al contador
  Si me encuentro me encuentro una comida, añado una al contador.
  No anoto la comida porque dentro del mapa ya tengo una variable que hace recuento de las comidas

5. **_MAP_VERIFY_WALLS_**

__Estructura s_map_way_verify_

* int		food_left = los comestibels que quedan
*	int		passed_exit = la salida

  1. **int	map_verify_walls(t_map *map)**

  2. static int	verify_side_walls(t_dstr *row)
  3. static int	verify_all_walls(t_dstr *row)

6. **_MAP_VERIFY_WAY_**
   Verifica que el mapa tenga un camino que sea correcto, que pueda realizarse.

  1. **int	map_verify_way(t_map *map)**
     LLama a walk_map para recorrer todos los movimientos validos posibles para poner una marca/banderita por donde pasa y asi poder recordarlo.
     Una vez que ha recorrido todo el mapa y ha puesto las banderitas, llama a loop_map para quitar esas banderitas y dejar el mapa original.
     Si me he comido todos los comestibles y puedo acceder a la salida, es que el mapa es valido.
  2. **static void walk_map(t_map *map, int x, int y, t_map_way_verify *verify)**
      Llama a visit_cell para visitar la posición x e y del jugador.
      Se llama recursivamente para ir visitando todas las celdas (llamada ->visit cell-> movimiento P->)
      Se acaba la recursividad cuando he pasado por la salida y me he comido todos los comestibles o si la celda no es valida porque se ha salido o ha chocado por la pared.O hay una banderita y ya he estado.
  3. **static int	visit_cell(t_map *map, int x, int y, t_map_way_verify *verify)**
      Declaro ch y llamo a la funcion map_at para que me diga que hay en esa posicion(C,E,O)(Comestible, salida o nada).
      Si es un comestible me queda una menos por comer
      Si es una salida, pongo el valor a 1 (True) para indicar que he pasado por la salida.
      Para que el jugador no pase por dondeya ha pasado o borro lo que habia cuando ha pasado o me hago uan copia del mapa o pongo una marca. Un bit.
      Vuelvo a llamar a map_at pero esta vez para ponerle la marca, cambiar el valor que hay por la marca.
      Valores que manejo estan en ASCII entre 32 y el 127.
      E = 69 -> 01000101
      C = 67 -> 01000011
      P = 80 -> 01010000
      Todos tiene el primer bit a cero asi que uso la funcion map_at y la operacion OR para poner ese bit a 1 y dejar una marca.
      Asi cuando el jugador pase por ahí lo que se encuentre será distinto a lo anterior y sabrá que por ahí ya ha pasado.
         0100 0011 = C
      OR 1000 0000 = 128
      ------------
         1100 0011
              
	4. **static int	is_valid_cell(t_map *map, int x, int y)**
     Si el player se sale por la pared por arriba, por abajo,  derecha o izquiera -> no es valido. 
     LLamamos a la funcion map_at para saber que hay en ch, en la celda.
     Si es pared o el resultado de pasarle al valor de la celda en bits la operacion logica AND y el resultado es 128, primer bit es 1.
     Me indica que ya he pasado por ahí, return 0 (False)
	        1100 0011 = C
      AND 1000 0000  = 128     
      -------------
          1000 0000 
  5. **static int	unmark_cell_function(t_map_loop *map_loop)**
     Llamo a la funcion map_at para que me diga lo que hay y lo cambie, restituya el valor anterior.
     y recorro el valor pasandole la operacion logica AND 127 -> 0111 1111 y devolviendo el valor que había.
     Marco, desmarco pero no destruyo.
          1100 0011 = C
      AND 0111 1111  = 127     
      -------------
          0100 0000 = C
    
7. **_MAP_** : Modulo para representar el mapa.
  Este módulo define el mapa del juego y la lógica básica del juego, como la verificación del mapa, el movimiento del jugador y la detección del fin del juego. Este módulo es "agnóstico en cuanto a la visualización", lo que significa que no asume dónde ni cómo se mostrará el mapa. 
  Como resultado, este módulo no depende de MinilibX.

  1. **void	map_destroy(t_map *map)** libera la reserva para el mapa (listas y el calloc)
  2. **int	map_move_player(t_map *map, int inc_x, int inc_y)**
    Intenta mover al jugador. Si el movimiento es válido, esto cambiará los campos actuales "player_x" y "player_y".
  Parámetros:
    - "map" el "t_map" en el que se realizará el movimiento
    - "inc_x" número de celdas para mover al jugador a la derecha (si es positivo) o a la izquierda (si es negativo)
    - "inc_y" número de celdas para mover al jugador hacia abajo (si es positivo)  o hacia arriba (si es negativo)
  Devuelve verdadero (distinto de cero) si el movimiento fue válido y el jugador ahora está posicionado en su nuevo 
  "player_x" y "player_y". La ubicación del jugador anterior ahora contendrá cualquier personaje que estuviera allí antes,
  a menos que fuera un alimento, en cuyo caso habrá desaparecido (reemplazado por un personaje MAP_EMPTY_CHAR)
  Devuelve falso (cero) si el movimiento no fue válido (ya sea que se intentó mover hacia una pared o más allá de los límites del mapa)
  3. **int		map_is_over(t_map *map)**
     Devuelve verdadero (distinto de cero) si el jugador está ubicado en la celda que contiene la salida y no queda comida para ninguno
     Devuelve falso (cero) en caso contrario
  4. **void	map_loop(t_map *map, int (*fn)(t_map_loop *), void *data)**
    Función que visita cada celda del mapa y llama a una función para cada una de estas celdas.
    Parámetros:
    - "map": la instancia "t_map" a recorrer
    - "fn": la función "callback" a llamar para cada celda. Esta función * recibirá una estructura que contiene todos los detalles
       de la celda que se está visitando, lo que le da a la función la información necesaria para realizar la tarea que necesita.
    - "data": datos adicionales que se pasan a la función callback. Esto puede ser necesario si la información "t_map_loop" que se 
       pasa como parámetro no es suficiente para la tarea que debe realizar.
    Vamos a explicarlo con un ejemplo:
    Una de las verificaciones del mapa verifica si hay un jugador, una salida y al menos un alimento. Para realizar esta verificación, 
    se llama a esta función pasando "t_count_data" (ver "map_verifications.h") como "datos" adicionales.
    Por lo tanto, para cada celda, se llamará a la función de devolución de llamada con el carácter en cada celda. La función de 
    devolución de llamada puede entonces verificar el carácter y actualizar el "t_count_data" con la cantidad de alimentos, jugadores y salidas.
     
8. **_MAP_AT:**
  1. **char	map_at(t_map *map, int column, int row, char ch)**
     Te devuelve y te permite cambiar un char del mapa.
     Por lo tanto obtener la fila/linea donde esta el char que queremos obtener/cambiar (una linea es un tdstr) y dentro de esa linea
     le pedimos que nos devuelva, barra cambie. 


 return (dstr_char_at(list_get(map->rows, row), column, ch));
9. _GAME_:
  1. static int	close_window(t_game *game)
  2. static int	key_press_hook(int key, t_game *game)
  3. void	game_destroy(t_game *game)
  4. void	game_run(t_game *game)
10. _GAME_CREATE_:
  1. static void	create_map(t_game *game, const char *map_file_name)
  2. static int	verify_map_fits_into_screen(t_game *game)
  3. t_game	*game_create(const char *map_file_name)
11. _GAME_DRAW_MAP_
   1. static int	draw_map_cell(t_map_loop *map_loop)
   2. static int	print_text(t_game *game, const char *text, int x, int y)
   3. static int	print_number(t_game *game, int number, int x, int y)
   4. int	game_draw_map(t_game *game)
12. _IMAGES_: Almacen de imagenes.Las imagenes que tiene el juego.
   1. t_images	*images_load(void *mlx)
   2. void	images_destroy(t_images *images)

13. _FONT_: Almacen de imagenes. Imagenes de los caracteres para escribir.
   1. static int	get_char_index(char ch)
   2. static char	*get_char_file_name(char ch) // ./font/***.xpm
   3. t_font	*font_load(void	*mlx)
   4. void	font_destroy(t_font *font)
   5. void	*font_get(t_font *font, char ch)
14. _UTIL_ 
   1. void	*util_calloc(size_t size)
   2. void	*util_load_image(void *mlx, char *file_name)
   3. void	util_destroy_image(void *mlx, void *image)
   4. int	util_display_error(const char *message, int return_code)



