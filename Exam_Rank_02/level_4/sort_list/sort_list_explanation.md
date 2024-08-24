## Subject

In this exercise we are asked to sort the list based on a set of arguments (a pointer to a list and a comparison function with two integers) according to the criteria established by the function passed to us. We do not know what the criteria is, but we have to use it.
**Reference functions with different comparison criteria.**
- ascenbding function -> sort from smallest to largest.
- descending function -> sort from largest to smallest.
- peers_first function -> sort from peers first and smallest second.

**best_search_order** function
This function, following the criteria of the comparison functions, displays the memory address of the best positioned node, which would be the one that should be in the first position.
1. We declare a t_list pointer auxiliary where to point when we find the node best by now.
2. Aux starts pointing at the same memory address than list.
3. Loop with the condition that list->next doesn't point to NULL, the end of the list.
4. If the result to call the cmp function is zero (false) means that aux is not the best positionedand list -> is teh best positioned so far.
5. Iter list->next
6. While loop finishes return aux.

**sort_list** function

1. We declare a pointer t_list best to store the first, once we called the **best_search_order** function.
2. The end of recursivity is when the list point to NULL, the end of the list.
3. Store in best variable the result of calling the **best_search_function**.
4. We declare an aux variable where we are going to store the data of list.
5. The data of list we are going to store the data of best variable.
6. The data of best we are going to put the value of aux.
7. Then we are going to call again to the function **sort_list** to repeat teh process but with small list. ** RECURSIVITY**
8. Return list.
