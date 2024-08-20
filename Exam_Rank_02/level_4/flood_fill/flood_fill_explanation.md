## Commented Solution
This exercise is about a map that you are given to represent in a two-dimensional array, an array of arrays, in which each element of that array is an array (a row of the map and each position is a column).
To locate a point on that map you need some coordinates, x and y.
Instead of two variables, we are given a structure with those two fields (x and y).
- char ** tap = map with char 1 and 0 (48 or 49)
- t_point size = dimensions of the map, num columns and rows.
- t_point begin = starting point (x and y).
You have to put an F at that initial point and take that value as a reference. If at that point, the content is 1, we will change all the 1s to F
If at that point, the content is 0, we will change all the 0s to F.
We will check above, to the right, to the left and below, what is in those cells, so that if the content is the same as the content of the cell where we started (t_point begin), we will change it to an F.

~~~
 |0|1|2|3|4|5|6|7| **Eje x**
 -----------------
0|1|1|1|1|1|1|1|1|
 ----------------
1|1|0|0|1|0|0|0|1|
 ----------------
2|1|0|0|1|0|0|0|1|
 ----------------
3|1|0|1|1|0|0|0|1|
 ----------------
4|1|1|1|0|0|0|0|1|
 ----------------
 **Eje y**
 ~~~
 ~~~
  0 1 2 3 4 5 6 7   **Eje x**
 -----------------
0|F|F|F|F|F|F|F|F|
 ----------------
1|F|0|0|F|0|0|0|F|
 ----------------
2|F|0|0|F|0|0|0|F|
 ----------------
3|F|0|F|F|0|0|0|F|
 ----------------
4|F|F|F|0|0|0|0|F|
 ----------------
 **Eje y**
 ~~~
1. We need to save the value of the starting point so we declare a variable of type char "char content".
2. In Content we will put the value that is in that t_point begin.
3. Now we can put an F in that point, because we have saved the previous content in content.
4. From now on we start the movements:
- We declare a t_point movement to perform the movements.

~~~
- Move down:
~~~
-We leave the x field (row) fixed and add 1 to the y field (column).
-But it may be positined in the last row so we should consider it.
-**Condition** -> if after adding 1 to the y field of the starting point, it is greater than or equal to the number of rows that they have given me, it means that I do not go out of the frame and that I can move down.
and I also have to check that the content of this new cell, is the same as the content of the starting cell.
-If it is the same I change it for an F, if not, I leave it the same.
- **At this point, if I continue moving I have to do the same in each movement, so I use RECURSIVITY, to call myself and do the same.**
~~~
- Move up:
~~~
-We leave the x field (row) fixed and subtract 1 from the y field (column).
-But it may be in the first row so we should take it into account.
-**Condition** -> if after subtracting 1 from the y field of the starting point, it is greater than or equal to 0 (the first row), it means that I do not go outside the frame and that I can move up.
and I also have to check that the content of this new cell is the same as the content of the starting cell.
-If it is the same I change it for an F, if not, I leave it the same.
-**Again I call myself RECURSIVITY to do the same in the next movement.**
~~~
- Move to the left:
~~~
-We leave the y field (column) fixed and subtract 1 from the x field (column).
-But it may be in the first column so we should take it into account.
-**Condition** -> if after subtracting 1 from the x field of the starting point, it is greater than or equal to 0 (the first column), it means that I do not go outside the frame and that I can move to the left.
and I also have to check that the content of this new cell is the same as the content of the starting cell.
-If it is the same I change it to an F, if not, I leave it the same.
-**Again I call myself RECURSIVITY to do the same in the next movement.**
~~~
- Move to the right:
~~~
-We leave the y field (column) fixed and add 1 to the x field (column).
-But it may be in the last column so we should take it into account.
-**Condition** -> if after adding 1 to the x field of the starting point, it is less than the number of columns that we are given in size, it means that I am not leaving the frame and that I can move to the right.
and I also have to check that the content of this new cell is the same as the content of the starting cell.
-If it is the same I change it to an F, if not, I leave it the same.
-**Again I call myself RECURSIVITY to do the same in the next movement.**
~~~

**Explanation in spanish**

Este ejercicio trata de que te dan un mapa para representarlo en un array bi dimensional, un arrays de arrays, en el que cada elemento de ese array es un array ( fila del mapa y cada posicion es una columna).
Para localizar un punto en ese mapa necesitas unas coordenadas, x e y.
En lugar de dos variables nos dan una structura con esos dos campos (x e y).
char ** tap  = mapa con char 1 y 0 (48 o 49)
t_point size = dimensiones del mapa, num columnas y filas.
t_point begin = punto de partida (x e y).
Hay que poner una F en ese punto inicial y coger ese valor como referencia. 
Si en ese punto, el contenido es 1, cambiaremos todos los 1 por F
Si en ese punto , el contenido es 0, cambiaremos todos los 0 por F.
Chequearemos arriba, a la derecha, a la izquierda y abajo, qué hay en esas celdas, para que en caso de que el contenido sea igual que el contenido de la celda donde empezamos (t_point begin), lo cambiemos por una  F.

~~~
 |0|1|2|3|4|5|6|7| **Eje x** 
 -----------------
0|1|1|1|1|1|1|1|1|
 ----------------
1|1|0|0|1|0|0|0|1|
 ----------------
2|1|0|0|1|0|0|0|1|
 ----------------
3|1|0|1|1|0|0|0|1|
 ----------------
4|1|1|1|0|0|0|0|1|
 ----------------
 **Eje y**
 ~~~
 ~~~
  0 1 2 3 4 5 6 7 **Eje x**
 -----------------
0|F|F|F|F|F|F|F|F|
 ----------------
1|F|0|0|F|0|0|0|F|
 ----------------
2|F|0|0|F|0|0|0|F|
 ----------------
3|F|0|F|F|0|0|0|F|
 ----------------
4|F|F|F|0|0|0|0|F|
 ----------------
 **Eje y**
 ~~~
 1. Necesitamos guardar el valor del punto inicial asi que nos declaramos una variable de tipo char "char content".
 2. En Content meteremos el valor que haya en ese t_point begin. 
 3. Ahora ya podemos meter en ese punto una F, porque tenemos guardado el contenido anterior en content.
 4. A partir de ahora empezamos los movimientos :
    - Nos declaramos un t_point movement para realizar los movimientos.
~~~
    - Hacia abajo:
~~~
      -Dejamos fijo el campo x (fila) y sumamos 1 al campo y(columna).
      -Pero puede que este en la ultima fila por lo que debemos contemplarlo.
      -Condicion -> si despues de sumar 1 al campo y del punto de partida, es mayor o igual que el numero de filas que me han dado, es que no me salgo del marco y que puedo desplazarme hacia abajo .
      y ademas he de comprobar que el contenido de esta nueva celda es el mismo que el contenido de la celda de partida.
      -Si es el mismo lo cambio por una F, si no, lo dejo igual.
      - **En este punto, si sigo desplazandome tengo que hacer lo mismo en cada movimiento, por lo que uso la RECURSIVIDAD, para llamarme a mi mismo y hacer lo mismo.**
~~~
    - Hacia arriba:
~~~
      -Dejamos fijo el campo x (fila) y restamos 1 al campo y(columna).
      -Pero puede que esté en la primera fila por lo que debemos contemplarlo.
      -Condicion -> si despues de restar 1 al campo y del punto de partida, es mayor o igual que 0 (la primera fila ), es que no me salgo del marco y que puedo desplazarme hacia arriba.
      y ademas he de comprobar que el contenido de esta nueva celda es el mismo que el contenido de la celda de partida.
      -Si es el mismo lo cambio por una F, si no, lo dejo igual.
      -**Nuevamente me llamo a mi mismo RECURSIVIDAD para hacer lo mismo en el siguiente movimiento.**
~~~
    - Hacia la izquierda:
~~~
      -Dejamos fijo el campo y (columna) y restamos 1 al campo x(columna).
      -Pero puede que esté en la primera columna por lo que debemos contemplarlo.
      -Condicion -> si despues de restar 1 al campo x del punto de partida, es mayor o igual que 0 (la primera columna ), es que no me salgo del marco y que puedo desplazarme hacia la izquierda.
      y ademas he de comprobar que el contenido de esta nueva celda es el mismo que el contenido de la celda de partida.
      -Si es el mismo lo cambio por una F, si no, lo dejo igual.
      -**Nuevamente me llamo a mi mismo RECURSIVIDAD para hacer lo mismo en el siguiente movimiento.**
~~~
    - Hacia la derecha:
~~~
      -Dejamos fijo el campo y (columna) y sumamos 1 al campo x(columna).
      -Pero puede que esté en la última columna por lo que debemos contemplarlo.
      -Condicion -> si despues de sumar 1 al campo x del punto de partida, es menor que el numero de columnas que nos pasan en size, es que no me salgo del marco y que puedo desplazarme hacia la derecha.
      y ademas he de comprobar que el contenido de esta nueva celda es el mismo que el contenido de la celda de partida.
      -Si es el mismo lo cambio por una F, si no, lo dejo igual.
      -**Nuevamente me llamo a mi mismo RECURSIVIDAD para hacer lo mismo en el siguiente movimiento.**
~~~
