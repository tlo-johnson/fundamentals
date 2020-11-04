## [YouTube - Data Structures Easy to Advanced Course - Full Tutorial from a Google Engineer](https://www.youtube.com/watch?v=RBSGKlAvoiM&t=10442s)
A tree is an undirected graph which satisfies **any** of the following definitions:
- an acyclic connected graph
- a connected graph with N nodes and N-1 edges
- a graph in which any two vertices are connected by exactly one path

### Terimnology
- child: if node A extends from node B then node A is the child of node B
- parent: the inverse relationship of a child
- leaf node: a node with no children
- subtree: a tree entirely contained within another tree

A binary tree is a tree for which every node has **at most** two child nodes.

A binary search tree is a binary tree that satisfies the BST invariant: for every node, the left subtree has smaller elements than the current node and the right subtree has larger elements than the current node.

### Complexity Analysis
| Operation | Average | Worst |
| Insert | O(log(n)) | O(n) |
| Delete | O(log(n)) | O(n) |
| Remove | O(log(n)) | O(n) |
| Search | O(log(n)) | O(n) |

### Adding elements to a BST
1. Start at root
2. If element is less than current node, recurse down left subtree
3. If element is greater than current node, recurse down right subtree
4. If element is equal to current node, if tree supports duplicates, add a new node; if not, ignore value
5. If current node is null (i.e. parent is a leaf node), create a new node (i.e. insert new element)

### Removing elements from a BST
1. Find element to be removed
  a. Start at root
  b. If current node is null node, element does not exist in bst
  c. If element is less than current node, recurse down left subtree
  d. If element is greater than current node, recurse down right subtree
  e. If element is equal to current node, move on to next phase
2. Replace node with successor
  a. If node to remove is leaf node, simply remove it
  b. If node to remove has only one subtree, the successor of the node will be the root node of the subtree
  c. If node has two subtrees, the successor of the node can be either the largest value in the left subtree or the smallest value in the right subtree
    - note: to find the largst value in the left subtree, go to the left child, then go as far right as possible. once you can't go right anymore, you are at the largest value.
    - note: to find the smallest value in the right subtree, go to the right child, then go as far left as possible. once you can't go left anymore, you are at the smallest value.
    - once a successor node is chosen, copy the value of the successor to the node to be removed, then perform either 'a' or 'b' on the successor node - it will always be either case 'a' or 'b'
