## [YouTube - Data Structures Easy to Advanced Course - Full Tutorial from a Google Engineer](https://youtu.be/RBSGKlAvoiM?t=5493)
A priority queue (PQ) is an Abstract Data Type that operates similar to a normal queue with the exception that each element has a certain priority.
With each dequeue operation, the element with the highest priority is dequeued first.
Note: the highest priority does not necessarily mean the highest number (e.g. a min PQ will dequeue the lowest number first)

### Heaps
Note: A PQ is most efficiently modeled with a heap, so much so that the terms are used interchangeably. Be aware though that a PQ is an abstract data type while a heap is **ONE** implementation of a PQ.

A heap is a tree based data structure that satisfies the *heap invariant*: If A is a parent node of B then A is ordered with respect to B for all nodes A, B in the heap.
Min-heap invariant: If A is a parent node of B then A is less than or equal to B for all nodes A, B in the heap.
Max-heap invariant: If A is a parent node of B then A is greater than or equal to B for all nodes A, B in the heap.

Note: a heap does not have to be a binary heap.

### Uses
- some implementations of Dijkstra's Shortest Path algorithm
- fetching the "next best" or "next worst" element
- BFS algorithms (e.g. A\*) use PQs to grab the next most promising node
- Minimum Spanning Tree (MST) algorithms

### Complexity Analysis
| Binary Heap construction | O(n) | there's an algorithm for this |
| Polling | O(log(n)) | you need to reorder the heap to satisfy the heap invariant |
| Peeking | O(1) |
| Adding | O(log(n)) | you need to reorder the heap to satisfy the heap invariant |
| Naive Removing | O(n) | naive because a hash table can be used to improve performance |
| Naive contains | O(n) | naive because a hash table can be used to improve performance |

### Turning Min PQ to Max PQ
Simply negate a min PQ to get a max PQ and vice versa

### Adding and Removing Elements in a Binary Heap
Note: a complete binary tree is a tree in which every level, except possibly the last, is completely filled. If the last level is not completely filled, the nodes are as far left as possible.
![binary heap representation](./imgs/binary-heap-representation.png "binary heap representation")

When a binary heap is represented as an array:
- looping through the indexes of the array walks the binary heap from left to right, going through each level from top to bottom.
- left child index for any node is located at index 2n + 1 (0-based index)
- right child index for any node is located at index 2n + 2 (0-based index)

#### Algorithm for adding elements to a Binary Heap
1. Add node at insertion point. Insertion point is always at the lowest, leftmost available possition in the tree.
2. Bubble up till the heap invariant is satisfied.
  - bubbling is done by swapping the current node with its parent or child as required

#### Algorithm for adding elements to a Binary Heap
1. Find node to be removed. Usually this is the node at the root of the tree.
2. Swap removal node with node at the removal point. Removal point is always the lowest, rightmost node in the tree.
3. Bubble up/down till the heap invariant is satisfied
  - default to selecting the left child in the case where both child nodes are the same. why? (good question)
