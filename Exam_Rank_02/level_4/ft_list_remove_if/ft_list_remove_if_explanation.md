## Commented Solution

In this exercise we are given a list, a comparison function and the reference data to compare.
We have to keep in mind that lists can be of any type, so we use void * in the parameter type. But that means we need a reference data to know what to look for in the list.
Comparison functions return by convention **+ the number that is **when the second string is smaller, **0** when they are equal and **- the number that is **when the second string is greater than the first.

The list that they give me is ** because in the case that the reference data to be deleted was in the first node, I would lose the first node and then I would lose the reference of where the first one is, which now should point to the second.

When we delete nodes we have to take into account the previous and the next node between the node to be deleted.
This means that we have to iterate the previous and the next and it complicates the process a lot because the first node has a previous pointing to NULL, since it is the first one.

That is why we divide it into two, we assume that the first node remains fixed, that is, it does not have to be deleted and we compare the rest up to NULL with the reference argument to be deleted.

1. Corner Case = Loop that has as a condition that the result of the comparison is zero, then it enters the loop.
- Example = 2 2 3 2 1 2 --> reference value 2 --> we are asked to delete the 2.
- Since the first one is already a two, I enter the loop:
- We declare an auxiliary variable called **to_remove** where we are going to put the node to be deleted so as not to lose the reference of where that node to be deleted points to.
-New next node will point to the next address of the node to be removed.
nex_list = new_list->next
- Now we release to_remove, we can now remove it.

2. Pointer that has the value of where begin list is (* to a t_list) has to point to new_list so that when the nodes that contain the reference value are removed, it points to the first node that is different.

-*begin_lis = new_list

3. We should take into account a new corner case. All nodes contains the reference value, so the *begin_list point NULL.
   In this case, return, exit of the programme.

4. Now a new loop in which we leave the first node fixed, we already know that it does not contain the value that we are given to compare and
subsequently remove.
- We declare a variable result to put the result of the comparison of each node with the reference value.
- If the result is zero then:
- to remove = next node, the one we are going to remove, so we do not lose the address of where it points.
- the next of the new node is the next node of the previous one we are going to remove.
- and now that it points to the next node, we can delete the node.
- We do not iterate because we always leave the first one fixed so we do not have to iterate. When deleting the next one, it is as if we had iterated or moved a place.
- In case the reference value is not found when comparing, then it iterates to the next one.


**Spanish Version**
Tenemos que tener en cuenta que las listas pueden ser de cualquier tipo, por eso usamos void * en el parámetro type. Pero eso significa que necesitamos un dato de referencia para saber qué buscar en la lista.
Las funciones de comparación devuelven por convención **+ el número que es **cuando la segunda cadena es menor, **0** cuando son iguales y **- el número que es **cuando la segunda cadena es mayor que la primera.

La lista que me dan es ** porque en el caso de que el dato de referencia a eliminar estuviera en el primer nodo, perdería el primer nodo y luego perdería la referencia de donde está el primero, que ahora debería apuntar al segundo.
Cuando eliminamos nodos hemso de tener en cuenta el anterior y el posterior que entre el nodo a eliminar.
Eso hace que tengamos que iterar el previo y el posterior y complica mucho el recorrido porque el primer nodo tiene un previo apuntando a NULL, ya que es el primero.

Por eso la dividimos en dos, asumimos que el primer nodo se queda fijo o sea que no hay que eliminarlo y que comparamos el resto hasta NULL con el argumento de referencia a eliminar.

1. Corner Case = Loop que tenga como condicion que el resultado de la comparacion sea cero entonces entra en el bucle.
   - Ejemplo = 2 2 3 2 1 2 --> valor de referencia 2 --> se nos pide que eliminemos el 2.
   - Como el primero ya es un dos entro en el bucle: 
   - Nos declaramos una variable auxiliar llamada **to_remove** donde vamos a meter el nodo a eliminar para no perder la referencia de dodne apunta ese nodo a eliminar.
   -Nuevo nodo siguiente apuntara a la direcciond e meroia del siguiente al nodo a eliminar.
    nex_list  = new_list->next
    - Ahora liberamos to_remove, ya podemos eliminarlo.
  
2. puntero que tiene el valor de donde está begin list (* a un t_list) tiene que apuntar a new_list para que cuando se eliminen los nodos que contengan el valro de referencia, apunte al primer nodo que sea diferente.

  -*begin_lis = new_list
3. Tenemos que contemplar otro corner case. Podria ser que todos los nodos contuviesen el valor de referencia.
   Por lo tanto al salir del primer bucle el *pointer del principio apuntase a NULL.
   - En ese caso habria que saliurse del programa.
4. Ahora nuevo bucle en el que dejamos el primer nodo fijo, ya sabemos que no contiene el valor que nos pasan para comparar y posteriormente eliminar.
   - Nos declaramos una variable result para meter el resultado de la comparacion de cada nodo con el valor referencia.
   - Si el resultado es cero entonces :
	- to remove = siguiente nodo, el que vamos a eliminar, asi no perdemos la direccion de donde apunta.
 	- el next del nuevo nodo sea el siguiente del anterior al que vamos a eliminar.
	- y ahora que ya apunta al siguiente, podemos eliminar el nodo.
   - No iteramos porque siempre dejamos fijo el primero asi que no hay que iterar. Al borrar el siguiente, es como si hubiesemo iterado o corrido un lugar.
   - En caso que comparando no encuentre el valor de referencia, entonces si itera al siguiente. 
	   
