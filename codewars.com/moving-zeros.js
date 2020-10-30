/*
 * https://www.codewars.com/kata/52597aa56021e91c93000cb0/train/javascript
 * Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.
 */

const moveZeros = (arr) => arr.filter((x) => x !== 0).concat(arr.filter((x) => x === 0));
