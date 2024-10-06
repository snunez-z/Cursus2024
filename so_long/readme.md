## Explicacion del proyecto **so_long** 

Este proyecto es un pequeño juego en 2D. Está diseñado para trabajar con texturas y sprites junto algunos otros elementos básicos de jugabilidad.

**Indice**
. Que es so_long?
. Que utilizamos?
. Como funciona?

** Que es so_long?**
Este proyecto consiste en la creacion de un juego 2D, donde debes recoger todos los consumibles y escapar en la menor cantidad de movimientos posibles de un mapa creado por ti mismo!

En el siguiente ejemplo tenemos los siguientes componentes del mapa:

1111111  
1P0C0E1  
1111111  
◦ '1': Paredes, para poder jugar todo el mapa debe estar rodeado de ellos.

◦ 'P': Será el jugador y solo podra haber uno en todo el mapa.

◦ 'E': Será la salida y solo podra haber uno en todo el mapa.

◦ 'C': Los consumibles, podran haber tantos como gustes (minimo 1) y deberan ser alcanzables en todo momento.

Cabe recalcar que el mapa debe ser realizable en todo momento, en caso de que sea imposible, retornara error.

Por último estos serán los siguientes controles:

|-----------------------------------------------|
|TECLA  |ACCIÓN					                |
|-----------------------------------------------|
|W	    |Mover el personaje hacia arriba        |
|-----------------------------------------------|
|A	    |Mover el personaje hacia la izquierda  |	
|-----------------------------------------------|
|S	    |Mover el personaje hacia abajo		    |
|-----------------------------------------------|
|D	    |Mover el personaje hacia la derecha    |
|-----------------------------------------------|
|ESC    |Cierra el juego sin memory leaks	    |
|_______________________________________________|

**Que utilizamos?**

En nuestro so_long tenemos solo las siguentes funciones de librerias externas autorizadas:

 ___________________________________________________________________________________________________________
|Función	|Descripción											                                        |	
|___________|_______________________________________________________________________________________________|
| ft_calloc	|Solicitar un bloque de memoria del tamaño suministrado como parámetro.				            |
|-----------|-----------------------------------------------------------------------------------------------|
| free		|Desasigna un bloque de memoria que se había asignado previamente mediante una llamada. 	    |
|-----------|-----------------------------------------------------------------------------------------------|
| ft_printf	|Hace que los bytes que indiques del buffer sean escritos en el file descriptor seleccionado.	|
|-----------|-----------------------------------------------------------------------------------------------|
| open		|Abre el archivo del sistema seleccionado.							                            |
|-----------|-----------------------------------------------------------------------------------------------|
| close		|Cierra el archivo del sistema seleccionado.							                        |
|-----------|-----------------------------------------------------------------------------------------------|
| read		|Lee el contenido del archivo del sistema seleccionado.						                    |
|___________|_______________________________________________________________________________________________|
Tambien necesitaremos OBLIGATORIAMENTE la libreria minilibx para este proyecto.

**Como funciona?**

Para compilar el programa seguimos los siguientes pasos:

git clone https://github.com/snunez-z/so_long
cd so_long
make

Luego ejecutamos el programa pasandole de parametro la ubicacion del archivo del mapa:

./so_long maps/map.ber

¡Y eso seria todo!¡Estas liso para jugar!
