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
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int num_chessboard_rows, int num_obstacles, int r_q, int c_q, int obstacles_rows, int obstacles_columns, int** obstacles) {
  int top_squares = num_chessboard_rows - r_q;
  int bottom_squares = r_q - 1;
  int right_squares = num_chessboard_rows - c_q;
  int left_squares = c_q - 1;
  int top_left_squares = top_squares < left_squares ? top_squares : left_squares;
  int top_right_squares = top_squares < right_squares ? top_squares : right_squares;
  int bottom_left_squares = bottom_squares < left_squares ? bottom_squares : left_squares;
  int bottom_right_squares = bottom_squares < right_squares ? bottom_squares : right_squares;

  for (int index = 0; index < obstacles_rows; index++) {
    int r_obstacle = obstacles[index][0];
    int c_obstacle = obstacles[index][1];

    if (c_obstacle == c_q && r_obstacle > r_q) {
      int attackable_squares = r_obstacle - r_q - 1;
      if (top_squares > attackable_squares) top_squares = attackable_squares;
    }

    if (c_obstacle == c_q && r_obstacle < r_q) {
      int attackable_squares = r_q - r_obstacle - 1;
      if (bottom_squares > attackable_squares) bottom_squares = attackable_squares;
    }

    if (r_obstacle == r_q && c_obstacle > c_q) {
      int attackable_squares = c_obstacle - c_q - 1;
      if (right_squares > attackable_squares) right_squares = attackable_squares;
    }

    if (r_obstacle == r_q && c_obstacle < c_q) {
      int attackable_squares = c_q - c_obstacle - 1;
      if (left_squares > attackable_squares) left_squares = attackable_squares;
    }

    int delta = abs(r_obstacle - r_q);
    if (c_obstacle + delta == c_q && r_obstacle > r_q) {
      int attackable_squares = delta - 1;
      if (top_left_squares > attackable_squares) top_left_squares = attackable_squares;
    }

    if (c_obstacle - delta == c_q && r_obstacle > r_q) {
      int attackable_squares = delta - 1;
      if (top_right_squares > attackable_squares) top_right_squares = attackable_squares;
    }

    if (c_obstacle + delta == c_q && r_obstacle < r_q) {
      int attackable_squares = delta - 1;
      if (bottom_left_squares > attackable_squares) bottom_left_squares = attackable_squares;
    }

    if (c_obstacle - delta == c_q && r_obstacle < r_q) {
      int attackable_squares = delta - 1;
      if (bottom_right_squares > attackable_squares) bottom_right_squares = attackable_squares;
    }
  }

  return top_squares + bottom_squares + right_squares + left_squares + top_left_squares + top_right_squares + bottom_left_squares + bottom_right_squares;
}

int main()
{
    char** first_multiple_input = split_string(rtrim(readline()));

    int n = parse_int(*(first_multiple_input + 0));

    int k = parse_int(*(first_multiple_input + 1));

    char** second_multiple_input = split_string(rtrim(readline()));

    int r_q = parse_int(*(second_multiple_input + 0));

    int c_q = parse_int(*(second_multiple_input + 1));

    int** obstacles = malloc(k * sizeof(int*));

    for (int i = 0; i < k; i++) {
        *(obstacles + i) = malloc(2 * (sizeof(int)));

        char** obstacles_item_temp = split_string(rtrim(readline()));

        for (int j = 0; j < 2; j++) {
            int obstacles_item = parse_int(*(obstacles_item_temp + j));

            *(*(obstacles + i) + j) = obstacles_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, k, 2, obstacles);

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
