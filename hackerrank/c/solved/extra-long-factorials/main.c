#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */
int toDigit(char digit) {
  return digit - '0';
}

char toChar(int digit) {
  return digit + '0';
}

void addOne(char* num, int index) {
  if (num[index] == '\0') {
    num[index] = toChar(1);
    num[index + 1] = '\0';
    return;
  }

  int digit = toDigit(num[index]);
  int sum = (digit + 1) % 10;
  num[index] = toChar(sum);

  int carry = (digit + 1) / 10;
  if (carry != 0) addOne(num, ++index);
}

void add(char* num, char* addend) {
  int length = strlen(addend);

  for (int count = 0; count < length; count++) {
    int num_digit = toDigit(num[count]);
    int addend_digit = toDigit(addend[count]);
    int sum = (num_digit + addend_digit) % 10;
    num[count] = toChar(sum);

    int carry = (num_digit + addend_digit) / 10;
    if (carry != 0)
      addOne(num, count + 1);
  }
}

void multiply(char* result, int multiplicand) {
  char* multiplier = malloc(strlen(result) * sizeof(char) + 1);
  strcpy(multiplier, result);

  while (multiplicand-- > 1)
    add(result, multiplier);

  free(multiplier);
}

void extraLongFactorials(int n) {
  char* result = malloc(200 * sizeof(char));
  result[0] = toChar(1);
  result[1] = '\0';

  int count = 2;
  while (count <= n) {
    multiply(result, count++);
  }

  int length = strlen(result);
  for (int count = length - 1; count >= 0; count--)
    printf("%c", result[count]);

  free(result);
}

int main()
{
    int n = parse_int(ltrim(rtrim(readline())));

    extraLongFactorials(n);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
