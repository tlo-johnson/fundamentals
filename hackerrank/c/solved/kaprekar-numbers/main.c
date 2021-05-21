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
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

int isKaprekarNumber(int num) {
  long square = (long) num * num;

  int length = 0;
  while (square / (long) pow(10, length++) > 0);

  char* square_str = malloc(length-- * sizeof(char));
  sprintf(square_str, "%ld", square);

  int mid = length / 2;
  int left = 0;
  for (int index = mid - 1; index >= 0; index--) {
    int digit = square_str[index] - '0';
    left += digit * pow(10, mid - 1 - index);
  }

  int right = 0;
  for (int index = length - 1; index >= mid; index--) {
    int digit = square_str[index] - '0';
    right += digit * pow(10, length - 1 - index);
  }

  if (!(left + right == num)) return 0;
  printf("%d ", num);
  return 1;
}

void kaprekarNumbers(int p, int q) {
  int number_found = 0;
  while (p <= q)
    if (isKaprekarNumber(p++) && !number_found) number_found = 1;

  if (!number_found) puts("INVALID RANGE");
}

int main()
{
    int p = parse_int(ltrim(rtrim(readline())));

    int q = parse_int(ltrim(rtrim(readline())));

    kaprekarNumbers(p, q);

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
