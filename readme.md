# BYTES UNICODES

1. Que son los caracteres UNICODE ?

El ordenador solo sabe de números, por lo que a traves del codigo **ASCII**, a esos numeros se les da una interpretacion de un char.
Es solo una interpretacion de numeros como caracteres. El numero 65 como una a, lo saca por pantalla, o el 48 como un cero. 
Relaciona numeros con caracteres.(letras, números y otro tipo de caracteres (signos de puntuación
, símbolos, caracteres especiales, etc.). Pero llegó un momento en que la informatica creció y se globalizó asi que la tabla se quedó pequeña. Ya los 255 numeros 
que caben en un byte eran insuficientes.

> 1 Caracter = 1 byte y con sus 8 bits ya no eran suficientes y habia que dar forma a las particularidades de cada idioma.
> la ñ, los acentos, las direresis etc.

El terminal solo interpreta en funcion de la configuracion del ordenador, consola etc...y lo hace por acuerdo de que tipo de codificacion por cada byte diferente 
se va a dar.
Durante mucho tiempo hubo diferentes codificaciones pero al final se llego a un estandar mundial, los imprimibles se dejaban igual, son comunes para la mayoria de los 
idiomas pero el resto se utilizaban como caracteres especiales, para indicar que eran caracteres unicode.

---

Los numeros de ASCII que no se usan y en bloques en funcion de la procedencia de esos carcateres, se hace la interpretacion del siguiente modo:

.- Cuando te llegue un 195 no lo interpretes como un simbolo obsoleto del ASCII sino como una señal de que lo que va detras es un caracter unicode y lo vas a interpetar
   de forma distinta y como indique la codificacion de la terminal. 

Tiene que haber un acuerdo entre terminales, tienen que tener en su configuracion la misma codificacion para los caracteres UNICODE para que asi la maquina 
sea capaz de interpretar lo mismo y sacar por pantalla su representación del carácter.

UNICODE es el estandar mundial mas usado y lo que hace la maquian es interpetar los numeros que se les pasa de la siguiente forma:

1 Char ya no es un byte, puede ser 2 e incluso 3, dependiendo de si es un caracter pertenece a un bloque u a otro.
Pero detras de ese numero ya se sabe que viene un caracter UNICODE.
Ejemplo : áè

Ya no son 3 bytes ( 2 caracteres + 0), sino cinco + 0.
195 para indicar que es un codigo unicode, uno para la a, otro 195 para indicar que es un unicode y otro byte para la e + 0:
En nuestro codigo solo le afecta al server, que es el que descodificam, al cliente le da igual, el simplemente recibe un array de bytes y 
lo codifica en binario para enviarselo al server.

2. Que he hecho para que mi programa soporte caracteres UNICODE?

Mis dos programas codifican y descodifcan bytes.
El cliente recibe una cadena de bytes y la codifica y el server recibe una cadena de señales y las descodifica y las convierte en byteso sea en numeros.
Mientras ambas terminales tengan en su configuracion la misma codificacion, no necesitan nada, ya la terminal se encarga de interpretarlo.
