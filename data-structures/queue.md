## [YouTube - Data Structures Easy to Advanced Course - Full Tutorial from a Google Engineer](https://youtu.be/RBSGKlAvoiM?t=4558)
A queue is a linear data structure which models real world queues by having two primary operations, enqueue and dequeue - think a queue at a counter.
Queues operate in a first-in-first-out (FIFO) manner.
Note: a queue is an abstract data type.

### Uses
- Keep track of the x most recently added elements
- Web server request mgmt. where you want first come first serve basis
- **Breadth first search (BFS) graph traversal**

### Complexity Analysis (implementation using a DLL)
| Enqueue | O(1) | since we have a reference to the head |
| Dequeue | O(1) | since we have a reference to the tail |
| Peeking | O(1) | since we have a reference to the head |
| Contains | O(n) | since we have to search through the list|
| Removal | O(n) | since we have to search through the list |
| Is Empty | O(1) | since we have a reference to the head - is empty if head points to null |

### BFS graph traversal
Note: in a binary tree, this allows you traverse the entire tree from left to right going level by level.
1. visit current node.
2. add it to list of visited nodes.
3. add all unvisited neighbouring nodes to queue.
4. pop the next node off the queue.
5. repeat steps 1 through 4 till queue is empty

Note: this is identical to DFS traversal except that a queue is used instead of a stack.
