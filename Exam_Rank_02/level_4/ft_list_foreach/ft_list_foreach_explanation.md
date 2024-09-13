## Commented Solution

It is a list exercise in which for each node the content of the node is changed by applying a function to it. This function will receive a void * as an argument.

1. We declare a t_list pointer called list_pts and we match with the list received as argument *begin.
2. Loop to go thorow the list with the condition to not reach the end (NULL).
3. We apply the function (*F) establishing that the argument that the function must receive, whatever it may be, is the data field (content).
4. then iterate pointing to the next field.
