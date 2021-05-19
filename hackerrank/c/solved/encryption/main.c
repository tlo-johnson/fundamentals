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

/*
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
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
void removeSpaces(char* s) {
  int offset = 0;
  int length = strlen(s);
  int index = 0;

  for (index; index < length; index++) {
    int offset_index = index + offset;
    if (s[offset_index] != ' ') {
      s[index] = s[offset_index];
      continue;
    }

    offset_index = ++offset + index;
    while (s[offset_index] == ' ' && offset_index != length)
      offset_index = ++offset + index;

    if (offset_index == length) break;
    s[index] = s[offset_index];
  }

  s[index] = '\0';
}

char* encryption(char* s) {
  removeSpaces(s);

  int length = strlen(s);
  int num_rows = floor(sqrt(length));
  int num_columns = ceil(sqrt(length));

  if (num_rows * num_columns < length) num_rows++;

  // need space for result, including spaces (num_columns - 1) and null character
  char* result = malloc(length + (num_columns - 1) + 1 * sizeof(char));
  result[length] = '\0';

  int result_index = 0;
  for (int c_count = 0; c_count < num_columns; c_count++) {
    if (c_count != 0) result[result_index++] = ' ';
    for (int r_count = 0; r_count < num_rows; r_count++) {
      int position = (r_count * num_columns) + c_count;
      if (position >= length) continue;
      result[result_index++] = s[position];
    }
  }

  return result;
}

int main()
{
    char* s = readline();

    char* result = encryption(s);

    printf("%s\n", result);

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
