## [YouTube - Data Structures Easy to Advanced Course - Full Tutorial from a Google Engineer](https://www.youtube.com/watch?v=RBSGKlAvoiM)
A static array is a fixed length container containing n elements indexable from the range [0, n-1]. The elements in a static array are contiguous in memory.

### Complexity of operations
| | Static Array | Dynamic Array | Notes |
| access | O(1) | O(1) | |
| search | O(n) | O(n) | |
| insertion | n/a | O(n) | by definition, insertion includes resizing the array when necessary. this is obviously not possible with a static array |
| appending | n/a | O(1) | by definition, appending includes resizing the array when necessary. this is obviously not possible with a static array |
| deletion | n/a | O(n) | by definition, deletion includes resizing the array when necessary. this is obviously not possible with a static array |

## [Geeks for Geeks](https://www.geeksforgeeks.org/data-structures/)
When we have a small number of items, we can use variables (x, y, z, ...) to store them. If we want to store a large number of items, using variables becomes difficult. The idea of an array is to represent many items in one variable.

An array is a collection of items **stored contiguous memory locations**. This makes it easier to calculate the position of each element by simply adding an offset to a base value (i.e. the memory location of the first element of the array).
Note: a variable pointing to an array is typically a pointer to the memory location of the first element of the array
Note: the location of the next index depends on the data type of the array since different data types have different sizes

An array has a fixed size - once allocated, it can't be expanded (because we can't be sure the next memory location is available) and it can't be shrunk (because memory for an array is statically allocated).

Note: **a string is simply an array of characters**

### Advantages
- arrays allow random access of elements in constant time
- cache [locality](https://en.wikipedia.org/wiki/Locality_of_reference): the tendency to use items in an array together.
  - contrast this with a linked list where you might be using items together but still get many cache misses.

### Disadvantages
- inability to resize an array (i.e. an array is not dynamically sized)
- insertion and deletion of elements can be costly since the entire array may need to be re-allocated in memory

### [Complexity of operations](https://www.bigocheatsheet.com/)

### Terimnology
- base value: the value at index 0 of an array
- offset: the difference between the base value and an index in an array
- element: a data item in an array
- length: number of elements present in the array
