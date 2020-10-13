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
console.log(rotateWithSubArray([1, 2, 3, 4, 5, 6, 7], 2));
console.log(rotateWithSubArray([1, 2, 3, 4, 5, 6, 7], 4));

/*
 * recursive / functional approach
 */
const rotateRecursive = (arr, d) => {};
