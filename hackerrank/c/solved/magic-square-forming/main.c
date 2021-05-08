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
algorithm
---------
a 3x3 square always has a 5 in the middle
the outer ring is 1, 8, 3, 4, 9, 2, 7, 6 in a clockwise direction
four edge corner values are even numbers
four edge middle values are odd numbers

for each num on corner
  assume it's in the right spot
  calculate cost to get magic square
    calculate cost in a clockwise direction
    calculate cost in an anti-clockwise direction
  if cost is less than current max cost, storing cost in result
return result
 */

const int matrix_size = 3;

int getNextRow(int row, int col)
{
  int max_size = matrix_size - 1;
  int min_size = 0;

  if (col == max_size && row != max_size)
    row += 1;

  if (col == min_size && row != min_size)
    row -= 1;

  return row;
}

int getNextColumn(int row, int col)
{
  int max_size = matrix_size - 1;
  int min_size = 0;

  if (row == min_size && col != max_size)
    col += 1;

  if (row == max_size && col != min_size)
    col -= 1;

  return col;
}

int cost(int** matrix, int row_start, int col_start) {
  int row = row_start, col = col_start;
  int result = 100;
  int vals[][8] = {{ 8, 3, 4, 9, 2, 7, 6, 1 },
                  { 8, 1, 6, 7, 2, 9, 4, 3 }};

  for (int v_count = 0; v_count < 2; v_count++) {
    int curr_cost = 0;
    for (int count = 0; count < matrix_size * matrix_size - 1; count++) {
      int val = matrix[row][col];
      curr_cost += abs(val - vals[v_count][count]);

      int next_row = getNextRow(row, col);
      int next_column = getNextColumn(row, col);
      row = next_row;
      col = next_column;
    }
    result = curr_cost < result ? curr_cost : result;
  }

  result += abs(matrix[1][1] - 5); // middle num needs to be 5
  return result;
}

int formingMagicSquare(int s_rows, int s_columns, int** s) {
  int result = 100;

  for (int r_count = 0; r_count < matrix_size; r_count++) {
    for (int c_count = 0; c_count < matrix_size; c_count++) {
      if (!(r_count % 2 == 0 && c_count % 2 == 0)) continue;

      int curr_cost = cost(s, r_count, c_count);
      if (curr_cost < result) result = curr_cost;
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
