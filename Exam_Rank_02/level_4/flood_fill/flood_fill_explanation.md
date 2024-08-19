## Commented Solution

Este ejercicio trata de que te dan un mapa para representarlo en un array bi dimensional, un arrays de arraysm, en el que cada elemento de ese array es un array ( fila del mapa y cada posicion es una columna.
Para localizar un punto en ese mapa necesitas unas coordenadas, x e y.
En lugar de dos variables nos dan una structura con esos dos campos (x e y).
char ** tap  = mapa con char 1 y 0 (48 o 49)
t_point size = dimensiones del mapa, num columnas y filas.
t_point begin = punto de partida (x e y).
Hay que poner una F en ese punto inicial y coger ese valor como referencia. 
Si en ese punto, el contenido es 1, cambiaremos todos lso 1 por F
Si en ese punto , el contenido es 0, cambiaremos todos los 0 por F.
Chequearemos arriba, a la derecha, a la izquierda y abajo qué hay en esas celdas para que en caso de que el contenido sea igual que el contenido de la celda donde empezamos (t_point begin), lo cambiemos por una  F.

~~~
|0|1|2|3|4|5|6|7| Eje x 
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
 eje y
 ~~~
 ~~~
 |0|1|2|3|4|5|6|7| Eje x 
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
 eje y
 ~~~
 1. Necesitamos guardar el valor del punto inicial asi que nso declaramos una variable de tipo char "char content".
 2. En Content meteremos el valor que haya en ese t_point begin. 
 3. Ahora ya podemos meter en ese punto una F, porque tenemso guardado el contenido anterior en content.
 4. A partir de ahora empezamos los movimientos :
    - Nos declaramos un t_point movement para realizar los movimientos.
    - Hacia abajo:
~~~
      -Dejamos fijo el campo x (fila) y sumamos 1 al campo y(columna).
      -Pero puede que este en la ultima fila por lo que debemos contemplarlo.
      -Condicion -> si despues de sumar 1 al campo y del punto de partida, es mayor o igual que el numero de filas que me han dado, es que no me salgo del marco y que puedo desplazarme hacia abajo .
      y ademas he de comprobar que el contenido de esta nueva celda es el mismo que el contenido de la celda de partida.
      -Si es el mismo lo cambio por una F, si no, lo dejo igual.
      - En este punto, si sigo desplazandome tengo que hacer lo mismo en cada movimiento, por lo que uso la RECURSIVIDAD, para llamarme a mi mismo y hacer lo mismo.
~~~
    - Hacia arriba:
~~~
      -Dejamos fijo el campo x (fila) y restamos 1 al campo y(columna).
      -Pero puede que esté en la primera fila por lo que debemos contemplarlo.
      -Condicion -> si despues de restar 1 al campo y del punto de partida, es mayor o igual que 0 (la primera fila ), es que no me salgo del marco y que puedo desplazarme hacia arriba.
      y ademas he de comprobar que el contenido de esta nueva celda es el mismo que el contenido de la celda de partida.
      -Si es el mismo lo cambio por una F, si no, lo dejo igual.
      -Nuevamente me llamo a mi mismo RECURSIVIDAD para hacer lo mismo en el siguiente movimiento.
~~~
    - Hacia la izquierda:
~~~
      -Dejamos fijo el campo y (columna) y restamos 1 al campo x(columna).
      -Pero puede que esté en la primera columna por lo que debemos contemplarlo.
      -Condicion -> si despues de restar 1 al campo x del punto de partida, es mayor o igual que 0 (la primera columna ), es que no me salgo del marco y que puedo desplazarme hacia la izquierda.
      y ademas he de comprobar que el contenido de esta nueva celda es el mismo que el contenido de la celda de partida.
      -Si es el mismo lo cambio por una F, si no, lo dejo igual.
      -Nuevamente me llamo a mi mismo RECURSIVIDAD para hacer lo mismo en el siguiente movimiento.
~~~
    - Hacia la derecha:
~~~
      -Dejamos fijo el campo y (columna) y sumamos 1 al campo x(columna).
      -Pero puede que esté en la última columna por lo que debemos contemplarlo.
      -Condicion -> si despues de sumar 1 al campo x del punto de partida, es menor que el numero de columnas que nos pasan en size, es que no me salgo del marco y que puedo desplazarme hacia la derecha.
      y ademas he de comprobar que el contenido de esta nueva celda es el mismo que el contenido de la celda de partida.
      -Si es el mismo lo cambio por una F, si no, lo dejo igual.
      -Nuevamente me llamo a mi mismo RECURSIVIDAD para hacer lo mismo en el siguiente movimiento.
~~~
