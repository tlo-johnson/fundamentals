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
