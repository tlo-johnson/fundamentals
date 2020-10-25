## [YouTube - Data Structures Easy to Advanced Course - Full Tutorial from a Google Engineer](https://youtu.be/RBSGKlAvoiM?t=3506)
A stack is a one-ended linear data structure which models a real world stack by having two primary operations, push and pop - think of a stack of trays.
Stacks operate in a last-in-first-out (LIFO) manner.
Note: a queue is an abstract data type.

### Uses
- Undo mechanisms in text editors
- Matching brackets and braces.
  - you need to check that the bracket/brace matches each time you pop off the stack
  - you need to check that the stack is empty when you are done. 
- Recursion of function calls
- **Depth first search (DFS) graph traversal**

### Complexity Analysis (implementation using a linked list)
| Pushing | O(1) | since we have a reference to the top (head / tail) of the stack |
| Popping | O(1) | since we have a reference to the top (head / tail) of the stack |
| Peeking | O(1) | since we have a reference to the top (head / tail) of the stack |
| Searching | O(n) |
| Size | O(1) |

Note: when using a linked list for implementation, use a SLL and push/pop from the head
Note: you can use an array to implement a stack as well!!

### DFS graph traversal
Note: in a binary tree, this allows you traverse the entire tree from top to bottom (as opposed to from left to right ).
1. visit current node.
2. add it to list of visited nodes.
3. add all unvisited neighbouring nodes to stack.
4. pop the next node off the stack.
5. repeat steps 1 through 4 till stack is empty

Note: this is identical to BFS traversal except that a stack is used instead of a queue.
