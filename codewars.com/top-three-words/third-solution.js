/*
 * scan list character by character
 * if character is part of a valid word, join it to current word
 * if character is not part of a valid word
 *  look for current word in max prority queue
 *    if current word exists, add one to its priority
 *    if current word does not exist, add it to priority queue with a priority of 1
 * reset current word
 * repeat till all words have been stored
 *
 * retrieve max word from priority queue three times to form the array to be returned
 *
 * Time complexity: O(n log(k)) where k is number of words in text
 *  - n to go through text character by character, log(k) to store words in priority queue
 */

class maxPriorityQueue {
  items = [];

  add(item) {
    items.push(item);
    percolateUp(item);
  }

  const percolateUp = () => {
  }
}
