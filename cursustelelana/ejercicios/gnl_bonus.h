// Pon las cabeceras propias de un .h

// Declara la constante para cuántos ficheros simultaneos podemos tratar

// Necesitamos un struct gnl_bonus porque para cada fichero distinto del que
// queremos leer, necesitamos los tres datos que teníamos como static en la
// parte no bonus: el buffer, cuánto está ocupado y qué carácter hemos retornado
// Además, necesitamos un campo más para identificar a qué fd pertenece esta
// estructura
typedef struct gnl_bonus
{
	// Declara los tres campos que teníamos como static en read_one_char
	// más el fd
} t_gnl_bonus;

// Aquí vamos a declarar el array de ficheros de los que estamos leyendo
// Igual que en el caso del buffer dentro de gnl_bonus, como no todos los elementos
// del array van a estar ocupados, necesitaremos un campo para indicar cuántos
// están ocupados
typedef struct open_files
{
	// Declara el array (usa la constante que has declarado al principio del
	// archivo) y el campo que va a indicar cuántos elementos del array están ocupados
} t_open_files;

// Pon las cabeceras finales de un .h
