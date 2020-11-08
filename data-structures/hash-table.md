## [YouTube - Data Structures Easy to Advanced Course - Full Tutorial from a Google Engineer](https://youtu.be/RBSGKlAvoiM?t=14368)
A hashtable is a data structure that provides a mapping from keys to values via hashing.
Note: hashtable keys must be unique but their values do not have to be unique

### Hash Function
A hash function H(x) is a function that maps a key 'x' **to a whole number in a fixed range**.
Note: the fixed range part of this definition lends itself to modulus (i.e. hash functions use a modulus operator at the end to maintain that fixed range property ?)
Note: it's okay for a hash function to yield the same value given two different inputs. This is why collisions occur.

### Properties of Hash functions
- if H(x) = H(y) then x and y **might** be equal.
- if H(x) != H(y) then x and y are **definitely** not equal.
- H(x) must be deterministic (i.e. if H(x) = y, then H(x) must always equal y)
- ideally uniform in order to minimize the number of hash collisions

Note: Comparing hash values is constant time since a hash value is bounded by a fixed range
Note: checksums are simply hash values - complex hash function (actually cryptographic hash function) but simply a hash value nonetheless

### Hash Keys
- a key of type T is hashable if it is immutable (e.g. string, int)
- lists, sets, etc. are not good hash keys since we can add and remove elements from them.

### Hash Tables
A hash table is an array, indexed by a hash function (i.e. when storing a key/value in the array, the index of the value is determined by running the key through a hash function).
Note: a hash table can be thought of as a fancy name for an array of key value pairs where the key denotes the index of the array and the value is stored at that index.

### Hash Collisions
A hash collision occurs when multiple keys hash to the same value. There are many hash collision resolution techniques
- separate chaining: maintain a data structure (usually a linked list) to hold all the different values
- open addressing: find another place within the hash table for the object to go, offsetting it from the position it hashed to.

Note: separate chaining introduces auxillary data structures where open addressing maintains all values in one array.
Note: we need to store both the key and the value in the linked list because we need a way to distinguish between values that collided.
**Important Note:** we always store both the key and the value in a hash table so that we can find the right key in the case when a collision occurs.

##### Hash Table: Separate Chaining
In separate chaining, each index in the array holds a data structure (e.g a linked list contaning values) instead of directly holding the values being stored.
In order to maintain constant insertion and lookup time complexity once the HT gets really full you may need to create a new HT with a larger capacity and rehash all the items from the old HT.
Some other data structures used to track collisions are arrays, binary trees, self balancing trees, a hybrid of data structures, etc. Anything is possible really!!

##### Hash Table: Open Addressing
- Load factor (α): the number of items in the table / size of the table
Once our load factor gets close to some threshold, we need to grow the HT in order to maintain constant time behaviour. For example, given a max α of 0.667 and a table size (N) of 9, we would resize the hash table at N * α = 6.

When using open addressing, in the event of a collision we use a probing sequence P(x) to probe for the next available position, and we store our value there. If there are no available positions (i.e. the HT is full) we need to grow the HT.
Note: you should have grown the HT a long time before the HT becomes full based on the load factor of the HT.
When looking for a value, you use hash the key, use the probing sequence to find the next available positions until an empty position is found (or all positions are exhausted), before determining that the value does not exist. Obviously you return the value if you find it.

Some ways of probing:
- Linear probing: P(x) = ax + b
- Quadratic probing: P(x) = axx + bx + c
- Double hashing
- Pseudo random number generator

Pseudocode for insertion:
1. initialize x to 1, keyHash to H(k), index to keyHash
2. while (table[index] != null)
  a. index = (keyHash + P(k,x)) mod N
  b. x = x + 1
3. Insert (k,v) at table[index]
Note: H(k) is the hash for the key k adn P(k,x) is the probing function
Note: the probing function simply generates an offset from the current position!!
Note: the probing function always starts with x = 0 and then increments x when a collision occurs ... x has nothing to do with the key/value pair being inserted - it's simply a counter for the probing function.

One big problem with open addressing is when the probing sequence mod N will produce a cycle shorter than the table size. For example, imagine P(x) = 3x and a hash table of size 10. Once 3, 6 and 9 are filled up, our probing sequence will keep looping over those indexes although we may have other slots available in the hash table. The general solution to this is to choose a probing function that has a cycle of length N, given a hash table of size N. (i.e. the probing function should hit all indexes in the hash table before it cycles)

##### Hash Table: Open Addressing: Linear Probing
Remember: Linear probing is a probing function of the form P(x) = ax + b.
With linear probing, we get a probing function that produces a full cycle modulo N when 'a' and 'N' are relatively prime (i.e. their greatest common denominator is 1), denoted GCD(a,N) = 1
Note: when doubling (or tripling) your HT because you've hit your max load factor, you need to ensure the new HT size (N) still maintains the GCD(a,N) = 1 property. Also remember that you need to rehash all elements from your old table to your new table when you expand your table.

##### Hash Table: Open Addressing: Quadratic Probing

### Complexity
| Operation | Average | Worst |
| Insertion | O(1)\* | O(n) |
| Removal | O(1)\* | O(n) |
| Search | O(1)\* | O(n) |
Note: the constant time behavior is only true if you have a good uniform hash function.
