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
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */

/*
 * https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
 */

// pivot is the rightmost character that is less than its right neighbor
int findPivot(char* word, int word_length) {
  for (int index = word_length - 2; index >= 0; index--)
    if (word[index + 1] > word[index]) return index;
  return -1;
}

// pivot successor is rightmost character after pivot that is greater than pivot
int findPivotSuccessor(char* word, int word_length, int pivot) {
  int index = word_length;
  while (index > 1 && word[--index] <= word[pivot]);
  return index;
}

void swap(char* word, int this_index, int that_index) {
  int temp = word[this_index];
  word[this_index] = word[that_index];
  word[that_index] = temp;
}

// reverse the substring starting from pivot till end of word
void reverseSuffix(char* word, int word_length, int pivot) {
  int left_index = pivot + 1;
  int right_index = word_length - 1;
  for (int offset = 0; left_index + offset < right_index - offset; offset++)
    swap(word, left_index + offset, right_index - offset);
}

char* biggerIsGreater(char* word) {
  int word_length = strlen(word);

  int pivot = findPivot(word, word_length);
  if (pivot < 0) return "no answer";

  int pivot_successor = findPivotSuccessor(word, word_length, pivot);
  swap(word, pivot, pivot_successor);
  reverseSuffix(word, word_length, pivot);
  return word;
}

int main()
{
    int T = parse_int(ltrim(rtrim(readline())));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        char* w = readline();

        char* result = biggerIsGreater(w);

        printf("%s\n", result);
    }

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
