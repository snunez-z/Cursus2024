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


1. _DSTR_ : No sabemos el ancho del mapa, cuantas columnas tenemos que leer y guardar.
            Como no sabemos la longitud que tiene cada linea, necesitamos una estructura /modulo que nos permita añadir caracteres a un buffer y
            ese buffer crezca si es necesario.
  1. t_dstr	*dstr_create(void)
  2. void	dstr_destroy(t_dstr *dstr)
  3. char	dstr_char_at(t_dstr *dstr, size_t pos, char ch)
  4. int	dstr_append_char(t_dstr *dstr, char ch)
  5. size_t	dstr_length(t_dstr *dstr)

2. _LIST_ : Lo necesitamos porque no sabemos cuanta profundidad tiene el mapa, las filas que tenemos que leer. 
            En cada nodo de la lista vamos a meter un dstr, suamos las listas para poder añadir tantas como necesitemos.
  1. static t_list	*create_node(void *data)
  2. t_list	*list_append(t_list *list, t_dstr *data)
  3. void	list_destroy(t_list *list)
  4. size_t	list_size(t_list *list)
  5. t_dstr	*list_get(t_list *list, size_t pos)
3. _MAP_ :  Modulo para representar el mapa. Que va a tener ese modulo? La lista de las filas y la posicion actual del jugador.
            Esta es la funcion de creacion, que abre el mapa, lo lee y verifica que es correcto.
  1. void	map_destroy(t_map *map) libera la reserva para el mapa (listas y el calloc)
  2. int	map_move_player(t_map *map, int inc_x, int inc_y)
  3. int		map_is_over(t_map *map)
  4. void	map_loop(t_map *map, int (*fn)(t_map_loop *), void *data)
4. _MAP_AT:
  1. char	map_at(t_map *map, int column, int row, char ch)
5. _MAP_READ_
  1. static int	read_line_into_buffer(int fd, t_dstr *line)
  2.  static t_dstr	*read_line(int fd) // lee una linea y devuelve el * a dstr, que es una linea.
  3. static t_list	*read_file(int fd)
  4. static int	verify_map(t_map *map)
  5. t_map	*map_read(const char *file_name)
6. _MAP_VERIFICATIONS_
  1. static	int	count_function(t_map_loop *map_loop)
  2. int	map_verify_square(t_map *map)
  3. int	map_verify_items(t_map *map)
7. _MAP_VERIFY_WALLS_
  1. static int	verify_all_walls(t_dstr *row)
  2. static int	verify_side_walls(t_dstr *row)
  3. int	map_verify_walls(t_map *map)
8. _MAP_VERIFY_WAY_
  1. static int	is_valid_cell(t_map *map, int x, int y)
  2. static int	visit_cell(t_map *map, int x, int y, t_map_way_verify *verify)
  3. static void walk_map(t_map *map, int x, int y, t_map_way_verify *verify)
  4. static int	unmark_cell_function(t_map_loop *map_loop)
  5. int	map_verify_way(t_map *map)
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



