## My Solong explicacion.

El Solong es un proyecto de modulos y como en todos los modulos hay funciones de creacion, funciones de destruccion 
y en medio funciones que hacen cosas, de operaciones.Está el modulo del mapa, el módulo de las imagenes, el modulo de
la fuente (caracteres) y el módulo del juego.
El principal, el que engloba al resto es el **" game"**.**"game"** cuando se crea . crea a su vez el mapa. las imagenes
y la fuente. Y al destruirse hace lo mismo pero en orden inverso.

**Modulos**

DSTR : Lo necesitamos porque no sabemos el ancho del mapa, cuantas columnas tenemos que leer y guardar.
LIST : Lo necesitamos porque no sabemos cuanta profundidad tiene el mapa, las filas que tenemos que leer. 
MAP :  Modulo para representar el mapa. Que va a tener ese modulo? La lista de las filas y la posicion actual
del jugador.
map_read :
Esta es la funcion de creacion, que abre el mapa, lo lee y verifica que es correcto.


