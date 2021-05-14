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

void excludeBucketFor(int val, int* excluded_buckets, int divisor) {
  int excluded_bucket = divisor - (val % divisor);
  excluded_bucket = (excluded_bucket == divisor) ? 0 : excluded_bucket;
  excluded_buckets[excluded_bucket] = 1;
}

int nonDivisibleSubset(int divisor, int arr_count, int* arr) {
  /*
   * [ 19, 10, 12, 24, 25, 22 ]
   * 19 => 1, 5, 9, 13, 4n + 1 | 4 - (19 % 4) = 1
   * 10 => 2, 6, 10, 14, 4n + 2 | 4 - (10 % 4) = 2
   * 12 => 4, 8, 12, 16, 4n + 0 | 4 - (12 % 4) = 4
   *
   * 1 => 2, 5, 8, 3n + 2 | 3 - (1 % 3) = 2
   * 7 => 2, 5, 8, 3n + 2 | 3 - (7 % 3) = 1
   * 4 => same bucket
   * 2 => can't add because in 3n + 2 bucket
   */

  int max_count = 0;

  for (int outer_index = 0; outer_index < arr_count; outer_index++) {
    int* excluded_buckets = calloc(divisor, sizeof(int));

    int val = arr[outer_index];
    int bucket = val % divisor;
    void excludeBucketFor(val, excluded_buckets, divisor);
    int count = 1;

    for (int index = outer_index; index < arr_count; index++) {
      int val = arr[index];
      int bucket = val % divisor;

      if (excluded_buckets[bucket] != 0) continue;
      if (bucket == 0 && excluded_buckets[0] != 0) continue;

      int excluded_bucket = divisor - (val % divisor);
      excluded_bucket = (excluded_bucket == divisor) ? 0 : excluded_bucket;
      excluded_buckets[excluded_bucket] = 1;
      count++;
    }
    // need to repeat process for all permutations of outer index before moving on to next outer index
    if (max_count < count) max_count = count;
    free(excluded_buckets);
  }

  return max_count;
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
