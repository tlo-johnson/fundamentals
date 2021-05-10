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
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'beautifulDays' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER i
 *  2. INTEGER j
 *  3. INTEGER k
 */

int power(int base, int exponent)
{
  return (int) pow((double) base, (double) exponent);
}

int reverse(int day)
{
  // try implementing using scanf

  int num_digits = 0;
  while (day / power(10, ++num_digits) > 0);

  int* digits = (int*) malloc(num_digits * sizeof(int));
  num_digits--;

  int remainder = day;
  for (int exp = num_digits, count = 0; exp >= 0; exp--) {
    int divisor = power(10, exp);
    digits[num_digits - count++] = remainder / divisor;
    remainder = day % divisor;
  }

  int result = 0;
  for (int count = 0; count <= num_digits; count++)
    result += digits[count] * power(10, num_digits - count);

  free(digits);

  return result;
}

int isBeautifulDay(int day, int day_reversed, int divisor)
{
  return (abs(day - day_reversed) % divisor) == 0;
}

int beautifulDays(int i, int j, int k) {
  int num_beautiful_days = 0;

  for (i; i <= j; i++) {
    int day_reversed = reverse(i);
    if (isBeautifulDay(i, day_reversed, k))
      num_beautiful_days++;
  }

  return num_beautiful_days;
}

int main()
{
    char** first_multiple_input = split_string(rtrim(readline()));

    int i = parse_int(*(first_multiple_input + 0));

    int j = parse_int(*(first_multiple_input + 1));

    int k = parse_int(*(first_multiple_input + 2));

    int result = beautifulDays(i, j, k);

    printf("%d\n", result);

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

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
