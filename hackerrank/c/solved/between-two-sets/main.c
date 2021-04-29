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
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

/*
 * a = [2, 6] => 6, 12, 18, 24
 * b = [24, 36] => 6, 12
 * ans = 2
 *
 * a = [2, 4] => 4, 8, 12, 16
 * b = [16, 32, 96] => 4, 8, 16
 * ans = 3
 * 
 * a = [3, 4] => 4, 8, 12, 16, 20, 24
 * b = [24, 48] => 
 *
 * algorithm:
 * take max from a and min from b
 * find all multiples of a that are less than b
 * filter out multiples that aren't multiples of all elements of a
 * filter out multiples that don't factor into all elements of b
 *
 * another algorithm (not implemented):
 * find lcm of a
 * find gcd of b
 * count number of multiples of lcm that go into gcd
 */

int isFactorOfArrayElements(int b_count, int* b, int num) {
  int isFactor = 1;

  for (int count = 0; count < b_count; count++) {
    if (b[count] % num == 0) continue;
    isFactor = 0;
  }

  return isFactor;
}

int isMultipleOfArrayElements(int a_count, int* a, int num) {
  int isMultiple = 1;

  for (int count = 0; count < a_count; count++) {
    if (num % a[count] == 0) continue;
    isMultiple = 0;
  }

  return isMultiple;
}

int getTotalX(int a_count, int* a, int b_count, int* b) {
  int maxA = a[0];
  for (int count = 1; count < a_count; count++) {
    if (a[count] > maxA) maxA = a[count];
  }

  int minB = b[0];
  for (int count = 1; count < b_count; count++) {
    if (b[count] < minB) minB = b[count];
  }

  int num = maxA;
  int multiplier = 1;
  int result = 0;
  while (num <= minB) {
    num = maxA * multiplier++;
    if (isMultipleOfArrayElements(a_count, a, num) && isFactorOfArrayElements(b_count, b, num)) result++;
  }

  return result;
}

int main()
{
    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int m = parse_int(*(first_multiple_input + 1));

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(*(arr_temp + i));

        *(arr + i) = arr_item;
    }

    char** brr_temp = split_string(rtrim(readline()));

    int* brr = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        int brr_item = parse_int(*(brr_temp + i));

        *(brr + i) = brr_item;
    }

    int total = getTotalX(n, arr, m, brr);

    printf("%d\n", total);

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
