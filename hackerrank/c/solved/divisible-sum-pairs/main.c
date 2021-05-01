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
 * Complete the 'divisibleSumPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER_ARRAY ar
 */

int bruteForceDivisibleSumPairs(int n, int k, int ar_count, int* ar) {
  int result = 0;

  for (int i = 0; i < ar_count; i++) {
    int summand = ar[i];

    for (int j = i + 1; j < ar_count; j++) {
      int addend = ar[j];
      if ((summand + addend) % k == 0) result++;
    }
  }

  return result;
}

/*
 * the key to the better solution is:
 * any numbers satisfying num % k == 0 will match with any other number satisfying num % k == 0
 * any numbers satisfying num % k == 1 will match with any other number satisfying num % k == k - 1
 * any numbers satisfying num % k == 2 will match with any other number satisfying num % k == k - 2
 * any numbers satisfying num % k == x will match with any other number satisfying num % k == k - x
 *
 * intuitively, if n % k == 2, you need (k - 2) to get to the next multiple. so, a match will be any number that
 * satisfies n % k == k - 2
 */

int divisibleSumPairs(int n, int k, int ar_count, int* ar) {
  int* remainders = calloc(k, sizeof(int));

  for (int count = 0; count < ar_count; count++) {
    int val = ar[count];
    int remainder = val % k;
    remainders[remainder] += 1;
  }

  int result = 0;
  for (int count = 0; count <= k - count; count++) {
    if (count == 0 || count == k - count)
      result += (remainders[count] * (remainders[count] - 1)) / 2;
    else
      result += remainders[count] * remainders[k - count];
  }

  return result;
}

int main()
{
    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int k = parse_int(*(first_multiple_input + 1));

    char** ar_temp = split_string(rtrim(readline()));

    int* ar = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int ar_item = parse_int(*(ar_temp + i));

        *(ar + i) = ar_item;
    }

    int result = divisibleSumPairs(n, k, n, ar);

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
