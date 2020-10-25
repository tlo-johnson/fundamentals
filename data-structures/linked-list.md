## [YouTube - Data Structures Easy to Advanced Course - Full Tutorial from a Google Engineer](https://www.youtube.com/watch?v=RBSGKlAvoiM)
A linked list is a sequential list of nodes that hold data which point to other nodes also containing data

note: the last node of a linked list always has a null reference. circular lists are an "exception" to this rule, where there is no "last node".

### Terminology
- head: the first node in a linked list
- tail: the last node in a linked list
- pointer: a reference to another node. side note: pointers are really just variables. the "pointer" terminology essentially means that a node in a linked list has a variable that "contains" (more accurately "points to") the next node.
- node: an object containing data and pointer(s)
  - pointers (plural) in the case of a doubly linked list

### Singly vs Doubly Linked Lists
| | Pros | Cons |
| Singly Linked List | Uses less memory | Cannot easily access previus elements |
| | Simpler Implementation | |
| Doubly Linked List | Can be traversed backwards | Takes 2x memory |
| | | More complex implementation |

Memory differences are mainly due to the extra pointer that needs to be maintained in a doubly linked list.

### Inserting Singly Linked List
Note: trav is short for traversal
1. Add trav pointer at head
2. Seek up to but not including the node we want to be moved
3. Create new node
4. Make the new node point to trav.next
5. Make trav.next point to the new node

### Inserting Doubly Linked List
1. Add trav pointer at head
2. Seek up to but not including the node we want to be moved
3. Create new node
4. Make the newnode.next point to trav.next
5. Make the newnode.prev point to trav
6. Make trav.next.prev point to newnode
7. Make trav.next point to newnode

### Removing from Singly Linked List
This can be done using one trav pointer but for this case, we'll use two pointers.
1. Add trav1 pointer at head
2. Add trav2 pointer at head.next
3. Seek both trav1 and trav2 till trav2 is at the node to be removed
4. Add temp pointer to node to be removed
5. Move trav2 to temp.next
6. Make trav1.next point to trav2
7. Clean up memory for temp

### Removing from Doubly Linked List
1. Add trav pointer at head
2. Seek till we get to the node we want to remove
3. Make trav.prev.next point to trav.next
4. Make trav.next.prev point to trav.prev
5. Clean up memory for trav

### Complexity
| | Singly Linked (SLL) | Doubly Linked (DLL)| Notes |
| Search | O(n) | O(n) | you need to walk the linked list to find the node |
| Insert at head | O(1) | O(1) | |
| Insert at tail | O(1) | O(1) | |
| Remove at head | O(1) | O(1) | |
| Remove at tail | O(n) | O(1) | in SLL you don't have access to the tail's previous node so you need to walk the linked list to set the new tail |
| Remove in middle | O(n) | O(n) | since you have to walk the linked list to the position you want to remove |
