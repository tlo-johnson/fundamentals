#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int camelcase(char *str) {
  int numWords = 1;
  int length = strlen(str);
  for (int count = 0; count < length; count++)
    if (str[count] >= 'A' && str[count] <= 'Z')
      numWords++;

  return numWords;
}

int main() {
  int maxLength = 100000;
  char *str = malloc(maxLength * sizeof(char));
  scanf("%s", str);

  int result = camelcase(str);
  printf("%d\n", result);

  return 0;
}
