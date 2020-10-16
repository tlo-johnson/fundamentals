/*
 * https://www.geeksforgeeks.org/array-rotation/
 * Write a function rotate(arr, d, n) that rotates array arr of size n by d elements.
 *
 * arr = [ 1, 2, 3, 4, 5, 6, 7 ];
 * d = 2;
 * rotate(arr, d) = [ 3, 4, 5, 6, 7, 1, 2 ];
 */

/*
 * using temp array
 * time complexity: O(n)
 * space complexity: O(n)
 */
const rotateWithTempArray = (arr, d) => {
  const temp = [];
  for (let index = d; index < arr.length; index++) temp.push(arr[index]);
  for (let index = 0; index < d; index++) temp.push(arr[index]);
  return temp;
};
console.log("rotating with array");
console.log(rotateWithTempArray([1, 2, 3, 4, 5, 6, 7], 2));
console.log(rotateWithTempArray([1, 2, 3, 4, 5, 6, 7], 4));

/*
 * using temp sub-array
 * time complexity: O(n)
 * space complexity: O(d)
 * note: average space complexity is better than the temp array algorithm ( O(n/2) ?)
 */
const rotateWithSubArray = (arr, d) => {
  const temp = arr.slice(0, d);
  for (let index = d; index < arr.length; index++) arr[index - d] = arr[index];
  return [...arr.slice(0, arr.length - d), ...temp];
};
console.log("rotating with sub array");
console.log(rotateWithSubArray([1, 2, 3, 4, 5, 6, 7], 2));
console.log(rotateWithSubArray([1, 2, 3, 4, 5, 6, 7], 4));

/*
 * recursive / functional approach
 * time complexity: O(n * d) - you repeat d times and each time you repeat, you go through the entire array
 * space complexity: O(1)
 */
const rotateRecursive = (arr, d) => {
  if (d === 0) return arr;

  // rotate array by 1
  const firstElement = arr[0];
  for (let index = 1; index < arr.length; index++) arr[index - 1] = arr[index];
  arr[arr.length - 1] = firstElement;

  return rotateRecursive(arr, --d);
};
console.log("rotating recursive");
console.log(rotateRecursive([1, 2, 3, 4, 5, 6, 7], 2));
console.log(rotateRecursive([1, 2, 3, 4, 5, 6, 7], 4));

/*
 * juggling approach
 */
const rotateJuggle = (arr, d) => {
  for (let count = 0; count < d; count++) {
    // starting with base element, rotate elements that are d elements away
    const temp = arr[count];
    let index = count;
    for (; index < arr.length; index += d) {
      if (!(index + d < arr.length)) break;
      arr[index] = arr[index + d];
    }
    arr[index] = temp;
  }
  return arr;
};
console.log("rotating juggle");
console.log(rotateJuggle([1, 2, 3, 4, 5, 6, 7], 2));
console.log(rotateJuggle([1, 2, 3, 4, 5, 6, 7], 4));
