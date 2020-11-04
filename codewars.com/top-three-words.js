// https://www.codewars.com/kata/51e056fe544cf36c410000fb/train/javascript

const topThreeWords = (text) => {
  const counts = {};

  const words = text.toLowerCase().match(/[a-z][a-z']*/g);
  if (!words) return [];

  words.forEach((x) => {
    if (!counts[x]) counts[x] = 0;
    counts[x]++;
  });

  let first = (second = third = 0);
  let result = [];
  for (const word in counts) {
    if (counts[word] > first) {
      result = [word, ...result.slice(0, 2)];
      first = counts[word];
      continue;
    }

    if (counts[word] > second) {
      result = [result[0], word, ...result.slice(1, 2)];
      second = counts[word];
      continue;
    }

    if (counts[word] > third) {
      result = [result[0], result[1], word];
      third = counts[word];
    }
  }

  return result;
};
