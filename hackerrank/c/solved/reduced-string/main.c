#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* removeAdjacentDuplicates(char *str) {
  int length = strlen(str);

  int count = 0;
  for (; count < length - 1; count++)
    if (str[count] == str[count + 1])
      break;

  if (count == length - 1) return str;

  char *newStr = malloc((length + 1) * sizeof(char));
  int newStrCount = 0;
  for (; newStrCount < count; newStrCount++)
    newStr[newStrCount] = str[newStrCount];

  count += 2;
  if (count >= length) {
    newStr[newStrCount] = '\0';
    return newStr;
  }

  for (; count < length; count++) {
    newStr[newStrCount] = str[count];
    newStrCount++;
  }
  newStr[newStrCount] = '\0';
  return newStr;
}

char* reducedString(char *str) {
  int length = strlen(str);
  if (length == 0) return "Empty String";

  char *newStr = removeAdjacentDuplicates(str);
  if (strcmp(str, newStr) == 0) return str;

  return reducedString(newStr);
}

int main() {
  int maxLength = 100;
  char *str = malloc((maxLength + 1) * sizeof(char));
  scanf("%s", str);

  str = reducedString(str);
  printf("%s\n", str);

  return 0;
}
