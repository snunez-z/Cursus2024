**Ejercicios varios**
github de referencia:
.- https://github.com/abeph00/Push_Swap
.- https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
.- https://42-cursus.gitbook.io/guide/rank-02/push_swap/algorithms
Sistematizar 
1. Pongo el mas pequeño arriba y hago un pb y cuando la pila se queda vacia hago pa
2.-Pero si lo que esta debajo ya esta ordenado no es necesario llevarlo a la pila b
3.-Si el mas pequeño esta mas cerca de la cima ra, si esta mas cerca de abajo rra.
4. Si los dos de arriba son los mas pequeños pero el mas pequeño esta debajo, hago sa 
5. Si veo que voy a conseguir una pila ordenado hago sa antes de pb

__PUSH_SWAP- POSIBLE SOLUCION__
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
	**3 numeros** Objetivo que se ordenen en dos movimientos como maximo
		.- Comparo el superior con el del medio.
    	.- El del medio con el de abajo
		.- Abajo con el de arriba. 
    **5 números** Objetivo que se ordenen en maximo 12 movimientos.

	 Podemos usar la lógica de 3 números aleatorios para optimizar nuestro código. 
	 Mover los primeros dos números de la parte superior de la pila A y moverlos a la pila B. Recuperaremos esos números una vez que los tres números de la pila A estén ordenados del más pequeño al más grande.
	 **100 números** la mejor forma de optimizar los movimientos es diviendo los movimientos en paquetes de 5 (20). Tenes que hacerlo en menos de 700 movimientos.
	 	.-Fragmento 1 = 0 a 19 números.
        .-Fragmento 2 = 20 a 39 números.
		.-Fragmento 3 = 40 a 59 números.
		.-Fragmento 4 = 60 a 79 números.
		.-Fragmento 5 = 80 a 99 números.
    Comparo los numeros en funcion de cuan cerca estan del top o del botton, para ello cojo la lista y la divido en 2. Imagina 8 y 12.
	100/2, lo que nos da 50, que representaría la mitad de la lista. Luego encuentro el lugar donde está ese número dentro de la lista. El número 8 está en el segundo lugar (el número superior está en el lugar cero, porque se necesitan cero movimientos para llevar el número superior a la parte superior de la lista). Entonces tomo la ubicación de 8 e intento averiguar si la ubicación del número es mayor o menor que 50. Debido a que 2 es menor que 50, sé que sería más rápido ejecutar ra en el número 8 en lugar de rra. Pero el número 12 está en el lugar 96. Debido a que 96 es mayor que 50, sé que tengo que usar rra en él.
	**500 numeros** lo tienes que dividir en 11 fragmentos. Menos de 5500 movimientos

1. Stack a = 15 21 4 7 9
   Stack b = vacio
   Solucion = ra ra -> estan ordenados en dos bloques
2. Stack a = 6 10 1 5 9
   Stack b = vacio
   Solucion = rra sa ra ra ra -> el 9 necesito que suba arriba para intercambiarlo por el 6 y asi esten ordenados
3. Stack a = 10 9 6 5 1
    Stack b = vacio
	Solución = rra pb rra pb sa ra ra pa pa 
	ultimo de la pila es el mas pequeño, lo subo arriba y lo paso a la pila b

   