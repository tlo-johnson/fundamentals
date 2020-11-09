/*
 * scan list character by character
 * if character is part of a valid word, join it to current word
 * if character is not part of a valid word, store current word in hash table and reset current word
 *
 * once all words are stored in hash table, go through hash table and find max occurring word
 * delete max occuring word
 * repeat three times, to form the array to be returned
 *
 * Time complexity: O(n)
 */

const topThreeWords = (text) => {
  let currentWord = "";
  let words = {};

  for (let index = 0; index < text.length; index++) {
    const character = text[index];
    if (character.toLowerCase().match(/[a-z]/) || (currentWord && character === "'")) {
      currentWord += character.toLowerCase();

      if (!(index === text.length - 1)) continue;
    }

    if (currentWord) {
      if (!words[currentWord]) words[currentWord] = 0;
      words[currentWord]++;
      currentWord = "";
    }
  }

  const result = [];
  for (let count = 0; count < 3; count++) {
    let maxWord = "",
      maxCount = 0;

    for (let word in words) {
      if (words[word] > maxCount) {
        maxWord = word;
        maxCount = words[word];
      }
    }
    if (maxWord) result.push(maxWord);
    delete words[maxWord];
  }

  return result;
};
