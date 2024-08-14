## Commented Solution

1. Declare and inizialite an index and char pointer.
2. To get the size of src we run the string till '\0' and use the index to know how many characters src have.
3. Reserve memory with the measure of the  i + 1 for'\0'.
3. If it fails the reserve free & exit.
4. Run the src till the end. Copy character by character from teh src to copy.
5. When the loop exit, copy add the '\0' and return copy.
