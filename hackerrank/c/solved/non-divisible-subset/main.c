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
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

/*
 * group all numbers into their modulus buckets. comparing conflicting buckets, take the greater number of values.
 * e.g. comparing buckets 1 and 4, if bucket 1 has 3 numbers and bucket 4 has 1 number, add the 3 numbers from bucket 1.
 * this example assumes k = 5
 *
 * [ 19, 10, 12, 24, 25, 22 ] | k = 4
 * bucket 0 => 12, 24,
 * bucket 1 => 25,
 * bucket 2 => 10, 22
 * bucket 3 => 19, 
 *
 * only 1 num from bucket 0 can be accepted. total count: 1
 * buckets 1 & 3 both have 1 num. total count: 2
 * only 1 num from bucket 2 can be accepted. total count: 3
 */

int nonDivisibleSubset(int divisor, int arr_count, int* arr) {
  int* buckets = calloc(divisor, sizeof(int));

  for (int index = 0; index < arr_count; index++) {
    int bucket = arr[index] % divisor;
    buckets[bucket]++;
  }

  int count = 0;
  if (buckets[0] != 0) count++;
  for (int left_index = 1, right_index = divisor - 1; left_index <= right_index;) {
    if (left_index == right_index) {
      count++;
      break;
    }

    int num_left = buckets[left_index++];
    int num_right = buckets[right_index--];
    count += num_left > num_right ? num_left : num_right;
  }

  free(buckets);
  return count;
}

int main()
{
    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int k = parse_int(*(first_multiple_input + 1));

    char** s_temp = split_string(rtrim(readline()));

    int* s = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int s_item = parse_int(*(s_temp + i));

        *(s + i) = s_item;
    }

    int result = nonDivisibleSubset(k, n, s);

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
