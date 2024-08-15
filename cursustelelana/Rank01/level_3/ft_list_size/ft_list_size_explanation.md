## Commented Solution

A list is a structure in which there are two pieces of data.
One for the value it stores and another to point to the next one.

Any element in a list is a list. The length of a list is equal to the number of elements that compose it. However, depending on where the node is, the list will have a different length. 
Example: In a queue for the cinema, each person has a list of people who are ahead of them and it will be different depending on where you are positioned in the queue.

It is asked the number of elements of the list received.

1. We declare a len variable thats starts at 0.
2. Loop with the condition that the node doesn't point to null which in lists is the end of the list.
3. Iter the list one by one and the begin of the list will point to the next node till reach the end of the list.
   the last node of the list will point NULL.
4. Return NULL.

