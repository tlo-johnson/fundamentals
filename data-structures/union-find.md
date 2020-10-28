## [YouTube - Data Structures Easy to Advanced Course - Full Tutorial from a Google Engineer](https://youtu.be/RBSGKlAvoiM?t=8907)
Union Find is a data structure that keeps track of elements which are split into one or more disjoint sets. It's primary operations: *find* and *union*
- find: returns the group an element belongs to
- union: joins two groups together

### Uses
- Kruskal's minimum spanning tree algorithm
- Network connectivity

### Complexity Analysis
| Construction | O(n) |
| Union | amortized(n) |
| Find | amortized(n) |
| Get component size | amortized(n) |
| Check if connected | amortized(n) |
| Count components | O(1) |

### Creating Union Find
1. Create a bijection (a mapping) between objects and integers in the range [0, n)
  - this isn't required but it does allow us construct an array-based union find
  - the mapping of each element to an integer is arbitrary
2. Create an array of the objects based on the mapping in step 1
