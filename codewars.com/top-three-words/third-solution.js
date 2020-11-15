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

class MaxPriorityQueue {
  items = [];
  size = 0;

  add(item) {
    size === items.length - 1 ? items.push(item) : (items[maxIndex()] = item);
    percolateUp(size);
    size++;
  }

  remove() {
    const result = items[0];
    items[0] = items[--size];
    percolateDown(0);
    return result;
  }

  percolateUp = (currentIndex) => {
    if (currentIndex === 0) return;

    const parentIndex = currentIndex / 2;
    if (items[parentIndex] >= items[currentIndex]) return;

    swap(parentIndex, currentIndex);
    percolateUp(parentIndex);
  };

  percolateDown = (currentIndex) => {
    const leftChildIndex = currentIndex * 2;
    if (percolateDownChild(currentIndex, leftChildIndex)) return;

    const rightChildIndex = currentIndex * 2 + 1;
    percolateDownChild(currentIndex, rightChildIndex);
  };

  percolateDownChild = (currentIndex, childIndex) => {
    if (childIndex > maxIndex()) return false;
    if (!(items[childIndex] <= items[currentIndex])) {
      swap(currentIndex, childIndex);
      percolateDown(childIndex);
      return true;
    }

    return false;
  };

  swap = (index1, index2) => {
    const temp = items[index1];
    items[index1] = items[index2];
    items[index2] = temp;
  };

  maxIndex = () => size - 1;
}

const topThreeWords = (text) => {
  for (let index = 0; index < text.length; index++) {}
};
