** Get Next Line**

Assignment name : get_next_line
Expected files : get_next_line.c (42_EXAM can't take .h for now)
Allowed functions: read, free, malloc
--------------------------------------------------------------------------------

Write a function named get_next_line which prototype should be:
char *get_next_line(int fd);


Your function must return a line that has been read from the file descriptor passed as parameter. What we call a "line that has been read" is a succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

The line should be returned including the '\n' in case there is one at the end of the line that has been read. When you've reached the EOF, you must store the current buffer in a char * and return it. If the buffer is empty you must return NULL.

In case of error return NULL. In case of not returning NULL, the pointer should be free-able. Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be used as the buffer size for the read calls in your functions.

Your function must be memory leak free. When you've reached the EOF, your function should keep 0 memory allocated with malloc, except the line that has been returned.

Calling your function get_next_line() in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection, etc...

No call to another function will be done on the file descriptor between 2 calls of get_next_line(). Finally we consider that get_next_line() has an undefined behaviour when reading from a binary file.


**Spanish Version** 

scribe una función llamada get_next_line cuyo prototipo debería ser:
char *get_next_line(int fd);

Tu función debe devolver una línea que haya sido leída del descriptor de archivo pasado como parámetro. Lo que llamamos una "línea que ha sido leída" es una sucesión de 0 a n caracteres que terminan con '\n' (código ascii 0x0a) o con End Of File (EOF).

La línea debe devolverse incluyendo el '\n' en caso de que haya un \n al final de la línea que ha sido leída. Cuando hayas llegado al EOF, debes almacenar el buffer actual en un char * y devolverlo. Si el buffer está vacío, debes devolver NULL.

En caso de error, devuelve NULL. En caso de no devolver NULL, el puntero debe ser libre. Su programa se compilará con el indicador -D BUFFER_SIZE=xx, que debe usarse como tamaño de búfer para las llamadas de lectura en sus funciones.

Su función debe estar libre de fugas de memoria. Cuando haya alcanzado el EOF, su función debe mantener 0 memoria asignada con malloc, excepto la línea que se ha devuelto.

Por lo tanto, llamar a su función get_next_line() en un bucle le permitirá leer el texto disponible en un descriptor de archivo una línea a la vez hasta el final del texto, sin importar el tamaño del texto o de una de sus líneas.

Asegúrese de que su función se comporte bien cuando lea desde un archivo, desde la salida estándar, desde una redirección, etc.

No se realizará ninguna llamada a otra función en el descriptor de archivo entre 2 llamadas de get_next_line(). Finalmente, consideramos que get_next_line() tiene un comportamiento indefinido cuando lee desde un archivo binario
