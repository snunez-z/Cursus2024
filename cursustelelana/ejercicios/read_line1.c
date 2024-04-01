#include <unistd.h>

// Este ejercicio trata de que entiendas que las cinco funciones "read_one_char"
// que te presento aquí, hacen la misma cosa y funcionan de la misma forma, por
// lo tanto podrías usar la que te guste más (a mí la que más me gusta es la
// última). Cada una es una simplificación sobre la anterior versión.
// 
// RECUERDA! si a read le pedimos que lea 1 carácter, puede retornar:
// * -1 en caso de error
// *  0 si no ha podido leer nada
// *  1 si ha conseguido leer el carácter que le hemos pedido
// Esto es importante, porque asumir que va a retornar -1, 0 o 1 nos va a servir
// para simplificar las funciones
static int read_one_char(int fd, char *buffer)
{
	char	ch;
	int		read_result;

	read_result = read(fd, &ch, 1);
	// Protecciones
	if (read_result == -1)
		return -1;
	if (read_result == 0)
		return 0;

	*buffer = ch;
	return 1;

}

static int read_one_char(int fd, char *buffer)
{
	char	ch;
	int		read_result;

	read_result = read(fd, &ch, 1);
	// En la función anterior, si read_result era -1 retornabamos -1
	// y si read_result era 0 retornábamos 0...
	// Dicho otra vez:
	// * Si read_result == -1 => return -1
	// * Si read_result ==  0 => return  0
	// O sea... estábamos retornando el valor de read_result, así es
	// podemos simplificar las dos condiciones en esto:
	if (read_result <= 0)
		return read_result;

	*buffer = ch;
	return 1;
}

static int read_one_char(int fd, char *buffer)
{
	int		read_result;

	// No necesitamos "ch". Podemos pasar directamente "buffer". Por qué?
	// * Si la lectura falla, "read" no va a guardar nada en "buffer", así es que
	//   no corremos riesgo de "ensuciarlo" si algo va mal.
	// * Si la lectura va bien, en las versiones anteriores acabámos pasando el
	//   carácter leído a buffer; hacíamos:
	//   *buffer = ch;
	//   así es que... para qué usar "ch" si vamos a acabar pasándolo a buffer?
	//   Podemos usar "buffer" directamente
	read_result = read(fd, buffer, 1);

	if (read_result <= 0)
		return read_result;

	return 1;
}

static int read_one_char(int fd, char *buffer)
{
	int		read_result;

	read_result = read(fd, buffer, 1);
	// Mismo argumento que la segunda versión de la función:
	// * Si read_result == -1, retornamos -1
	// * Si read_result ==  0, retornamos  0
	// Ahora... qué hacemos si read retorna 1? Oh! sorpresa! retornamos 1!!!
	// * Si read_result == -1, retornamos -1
	// O sea... de nuevo... sea cual sea el valor de read_result, coincide con lo que
	// tenemos que retornar
	return read_result;
}

static int read_one_char(int fd, char *buffer)
{
	// Guardar el retorno de "read" para luego retornarlo tal cual y sin hacer nada
	// entre medias......... podemos simplificarlo en:
	return read(fd, buffer, 1);
}

