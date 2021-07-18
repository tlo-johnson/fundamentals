#include <stdlib.h>
#include <stdio.h>

int lengthRequirement(int length) {
  int minLength = 6;
  int diff = minLength - length;
  return diff > 0 ? diff : 0;
}

int isBetween(char character, char start, char end) {
  return character >= start && character <= end;
}

int digitRequirement(int length, char *password) {
  for (int count = 0; count < length; count++)
    if (isBetween(password[count], '0', '9')) return 0;

  return 1;
}

int lowercaseRequirement(int length, char *password) {
  for (int count = 0; count < length; count++)
    if (isBetween(password[count], 'a', 'z')) return 0;

  return 1;
}

int uppercaseRequirement(int length, char *password) {
  for (int count = 0; count < length; count++)
    if (isBetween(password[count], 'A', 'Z')) return 0;

  return 1;
}

int specialCharacterRequirement(int length, char *password) {
  for (int count = 0; count < length; count++)
    if (password[count] == '!' ||
        password[count] == '@' ||
        password[count] == '#' ||
        password[count] == '$' ||
        password[count] == '%' ||
        password[count] == '^' ||
        password[count] == '&' ||
        password[count] == '*' ||
        password[count] == '(' ||
        password[count] == ')' ||
        password[count] == '-' ||
        password[count] == '+')
      return 0;

  return 1;
}

int minimumNumber(int length, char *password) {
  int result = 0;
  result += digitRequirement(length, password);
  result += lowercaseRequirement(length, password);
  result += uppercaseRequirement(length, password);
  result += specialCharacterRequirement(length, password);
  result += lengthRequirement(length + result);

  return result;
}

int main() {
  int length;
  scanf("%d", &length);

  char *password = malloc((length + 1) * sizeof(char));
  scanf("%s", password);

  int result = minimumNumber(length, password);
  printf("%d\n", result);

  return 0;
}
