**KSORT ALGORITMO**

El algoritmo K-Sort es un enfoque de ordenamiento que implica dividir los elementos en pequeñas particiones o grupos, ordenarlos localmente y luego combinarlos de forma eficiente. Es útil para estructuras como pilas, donde solo tienes un conjunto limitado de operaciones disponibles.

En tu caso, con las pilas y los movimientos permitidos, el K-Sort puede adaptarse para dividir los números en subconjuntos manejables, pasarlos entre las pilas (a y b) y usar estrategias específicas para ordenarlos.

Pasos Básicos de K-Sort
1.- Dividir en grupos: Divide los números en k subconjuntos según algún criterio, como rangos. Por ejemplo, puedes agrupar números en bloques (0-99, 100-199, etc.).
2.- Mover a b y ordenar: Usa las operaciones permitidas para pasar números de a a b en grupos y ordenarlos en b.
3.- Volver a a ordenados: Devuelve los números de b a a en el orden correcto.
4.- Este proceso asegura que la pila a quede completamente ordenada.

__Ejemplo con Números__

Supongamos que tienes los números:

a = [42, 15, 8, 73, 23, 50, 95]
b = []
1. Dividir en grupos:
   Dividimos los números en dos bloques: [0-50] y [51-100].

	Primer grupo (0-50): [42, 15, 8, 23]
	Segundo grupo (51-100): [73, 50, 95]
	  
2. Mover el primer grupo a b:
   Usa operaciones pb para mover números del rango [0-50] a b.

	a = [73, 50, 95]
	b = [23, 8, 15, 42]

3.	Ordenar localmente en b:
	Usa operaciones como sb, rb, y rrb para ordenar los elementos en b.

	b = [8, 15, 23, 42]
	Mover el segundo grupo a b:
	Haz lo mismo con el rango [51-100].

	a = []
	b = [50, 73, 95, 8, 15, 23, 42]
	Volver a a en orden:
4. Usa pa para pasar los elementos de b a a en orden ascendente.

a = [8, 15, 23, 42, 50, 73, 95]
b = []

__Ventajas de K-Sort__

Divide el problema en partes más pequeñas, lo que facilita trabajar dentro de un límite de movimientos.
Ordenar localmente los grupos reduce la complejidad general.