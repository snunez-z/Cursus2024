# CONVERSION A BINARIOS.

Binario es base 2 
Decimal es base 10 
1 Byte tiene 8 bits, lo que significa que 0000 0000 = 0 en decimal y 1111 1111 = 255 en decimal.
Lo que significa que 1  
1 posicion 1 , resto se van multiplicando el resulado * 2 
Resultado final = 128 64 32 16 8 4 2 1 ( Mascaras)
En binario todos los bits estan a cero excepto 1 que es el que nos sirve para chequear.

1. **PASAR DIGITOS A BINARIOS**

 Estamos trabajando con bloques de 8 bits, con un entero que tiene 4 bytes- 32 bits, abarcariamos el maximo que podemos pasar a binario y el maximo que un ordenador recoger de un entero.
 Al igual que en base 10, en binario el numero más pequeño es el de la derecha y luego se van multiplicando * 2.
 En binario para 8 bits el número máximo que podemos convertir es 255.
  128 64 32 16 8 4 2 1
 * ejemplo si queremos saber en binario 225 seria 
  128 64 32 16 8 4 2 1
   1   1  1  0 0 0 0 1 = 225

2. **COMO VAMOS A CHEQUEAR ? Operaciones logicas**

Operaciones logicas - > es una operacion que trabaja a nivel de bits, en lugar de numeros, usa bits.
* AND & (un solo aspersan) 
0 & 0 = 0
1 & 0 = 0
0 & 1 = 0
1 & 1 = 1 Solo cuando el unico bit que tiene la mascara es 1 se encuentra con otro 1 en al misma posicion el resultado es 1.
Necesitas ser mayor de 18 años y ser socio, solo cuando traes las dos cosas puedes entrar.

* OR 
0 | 0 = 0 Solo cuando no se cumple ninguna de las dos condiciones es totalmente falso 
1 | 0 = 1
0 | 1 = 1
1 | 1 = 1 
Solo cuando traes el dni o autorizacion de tus padres puedes entrar, o una cosa u otra cosa, solo no puedes cuando no traes nada .


3. **COMO FUNCIONA LA OPERACION LOGICA AND**

Solo cuando el ultimo bit es 1 podemos desplazar a la izquiera la mascara del 1 y dejando a la derecha un bit 0. 
Con cada una de las mascaras:
00000001 1
00000010 2
00000100 4
00001000 8
00010000 16
00100000 32
01000000 64
10000000 128

48 = 00110000 se compara con la mascara del 1 
     00000001 
     --------
     00000000 = primer bit seria 0  

48 = 00110000 se compara con la mascara del 2 
     00000010
     --------
     00000000 = segundo bit = 0

48 = 00110000 se compara con la mascara del 4 
     00000100 
     --------
     00000000 = tercer bit seria 0  

48 = 00110000 se compara con la mascara del 8 
     00001000 
     --------
     00000000 = cuarto bit seria 0              

48 = 00110000 se compara con la mascara del 16
     00010000 
     --------
     00010000 = quinto bit seria 1  

48 = 00110000 se compara con la mascara del 32 
     00100000 
     --------
     00100000 = sexto bit seria 1  

48 = 00110000 se compara con la mascara del 64 
     01000000 
     --------
     00000000 = septimo bit seria 0  

48 = 00110000 se compara con la mascara del 128 
     10000000 
     --------
     00000000 = octavo bit seria 0  

4. **PARA CODIFICAR CARACTERES Y ENVIARLOS EN BINARIO.
    USAMOS LAS OPERACIONES LOGICAS**
    
    Si empiezas por la izquierda la mascara es 1000000 y has de dividir / 2 para avanzar Mask = 128
    Si empiezas por la derecha la mascara es 00000001 y has de multiplicar * 2 para avanzar Mask = 1;

```
     0 1 0 0 1 0 0 0 = 72 = 'H'
  &  1 0 0 0 0 0 0 0 = 128 = mask
     ---------------
     0 0 0 0 0 0 0 0 = 0


     0 1 0 0 1 0 0 0 = 72 = 'H'
  &  0 1 0 0 0 0 0 0 = 64 = mask
     ---------------
     0 1 0 0 0 0 0 0 = 1

     0 1 0 0 1 0 0 0 = 72 = 'H'
  &  0 0 1 0 0 0 0 0 = 32 = mask
     ---------------
     0 0 0 0 0 0 0 0 = 0  

     0 1 0 0 1 0 0 0 = 72 = 'H'
  &  0 0 0 1 0 0 0 0 = 16 = mask
     ---------------
     0 0 0 0 0 0 0 0 = 0     

     0 1 0 0 1 0 0 0 = 72 = 'H'
  &  0 0 0 0 1 0 0 0 = 8 = mask
     ---------------
     0 0 0 0 1 0 0 0 = 1   

     0 1 0 0 1 0 0 0 = 72 = 'H'
  &  0 0 0 0 0 1 0 0 =  4 = mask
     ---------------
     0 0 0 0 0 0 0 0 = 0       

     0 1 0 0 1 0 0 0 = 72 = 'H'
  &  0 0 0 0 0 0 1 0 =  2 = mask
     ---------------
     0 0 0 0 0 0 0 0 = 0       

     0 1 0 0 1 0 0 0 = 72 = 'H'
  &  0 0 0 0 0 0 0 1 =  1 = mask
     ---------------
     0 0 0 0 0 0 0 0 = 0  
```

     Resultado final de la codificacion de la H es        
