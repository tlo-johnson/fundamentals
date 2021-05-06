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
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

/*
 * 5 3 4
 * 1 5 8
 * 6 4 2
 *
 *
(+3) (+3) (+1) (+0)
  5    3    4  (+3)
  1    5    8  (+1)
  6    4    2  (+3)
               (+3)

 * magic constant for 3x3 square is 15
 *
 * missing numbers: 7, 9
 *
 * row 1: sum = 12, needs 3
 * column 1: sum = 12, needs 3
 * diagonal ltr: sum = 12, needs 3
 * add 3 to [1, 1]
 *
 * row 2: sum = 14, needs 1
 * column 3: sum = 14, needs 1
 * add 1 to [2, 3]
 *
 * row 3: sum = 12, needs 3
 * column 2: sum = 12, needs 3
 * add 3 to [3, 2]
 *
 * diagonal rtl: sum = 15
 *
 *
 *
 * 4 9 2
 * 3 5 7
 * 8 1 5
 *
 * missing number: 6
 * [3, 3]
 *
 * row deltas:    3, 1, 3
 * column deltas: 3, 3, 1
 *
 * 4 8 2
 * 4 5 7
 * 6 1 6
 *
 *

(+ 4) (+ 6) (+ 5) (+12)
   9     1     1  (+ 4)
   1     1     8  (+ 5)
   1     7     1  (+ 6)
                  (+ 4)

(+1) (+1) (+0) (+2)
  4    8    2  (+1)
  4    5    7  (-1)
  6    1    6  (+2)
               (+0)




missing numbers: 3, 9

14 16 13
14 14 15
15 13
corner sum: 18
diamond sum: 20
*
*

  4    9    2
  3    5    7
  8    1    6

  8    3    4
  1    5    9
  6    7    2

corners sum = diamond sum = 20

[0, 0] [0, 1] [0, 2]
[1, 0] [1, 1] [1, 2]
[2, 0] [2, 1] [2, 2]

algorithm
---------
a 3x3 square always has a 5 in the middle
the outer ring is 1, 8, 3, 4, 9, 2, 7, 6 in a clockwise direction
four edge corner values are even numbers
four edge middle values are odd numbers

set middle num to 5, storing difference in result
for each num on edge, assume it's in the right spot
calculate cost to get magic square, storing the minimum in result
 */

const int matrix_size = 3;

int cost(int** matrix, int row_start, int col_start) {
  for (int count = 0; count < matrix_size * matrix_size; count++) {
    int row = (row_start + count) % matrix_size;
    int val = matrix[row][col];
  }
}

int formingMagicSquare(int s_rows, int s_columns, int** s) {
  int result = 0;

  for (int r_count = 0; r_count < matrix_size; r_count++) {
    for (int c_count = 0; c_count < matrix_size; c_count++) {
      int temp = cost(s, r_count, c_count);
      if (temp < result) result = temp;
    }
  }

  return result;
}

int main()
{
    int** s = malloc(3 * sizeof(int*));

    for (int i = 0; i < 3; i++) {
        *(s + i) = malloc(3 * (sizeof(int)));

        char** s_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 3; j++) {
            int s_item = parse_int(*(s_item_temp + j));

            *(*(s + i) + j) = s_item;
        }
    }

    int result = formingMagicSquare(3, 3, s);

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
