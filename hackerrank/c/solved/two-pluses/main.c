#include <stdio.h>
#include <stdlib.h>

int** createGrid(int num_rows, int num_columns) {
  int* *grid = malloc(num_rows * sizeof(int*));

  for (int row_count = 0; row_count < num_rows; row_count++)
    for (int column_count = 0; column_count < num_columns; column_count++) {
      int *row = malloc(num_columns * sizeof(int));
      grid[row_count] = row;
    }

  return grid;
}

char isValidPlus(char* *grid, int num_rows, int num_columns, int row_count, int column_count, int offset) {
  char val = grid[row_count][column_count];
  if (val == 'B') return 0;

  if (row_count + offset >= num_rows ||
      column_count + offset >= num_columns ||
      row_count - offset < 0 ||
      column_count - offset < 0) return 0;

  return val == grid[row_count + offset][column_count] &&
    val == grid[row_count - offset][column_count] &&
    val == grid[row_count][column_count + offset] &&
    val == grid[row_count][column_count - offset];
}

int getMaxLength(int* *lengths, int num_rows, int num_columns) {
  int max = 0;

  for (int row_count = 0; row_count < num_rows; row_count++)
    for (int column_count = 0; column_count < num_columns; column_count++) {
      if (max > lengths[row_count][column_count]) continue;
      max = lengths[row_count][column_count];
    }

  return max;
}

char overlap(int length, int row, int column, int limit_length, int limit_row, int limit_column, int num_rows, int num_columns) {
  if (row == limit_row && column == limit_column) return 1;
  if (length == 0) return 0;

  int* *grid = createGrid(num_rows, num_columns);

  for (int offset = 0; offset <= length; offset++) {
    grid[row][column + offset] = 1;
    grid[row][column - offset] = 1;
    grid[row + offset][column] = 1;
    grid[row - offset][column] = 1;
  }

  for (int offset = 0; offset <= limit_length; offset++) {
    if (grid[limit_row][limit_column + offset] == 0 &&
        grid[limit_row][limit_column - offset] == 0 &&
        grid[limit_row + offset][limit_column] == 0 &&
        grid[limit_row - offset][limit_column] == 0) continue;

    free(grid);
    return 1;
  }

  free(grid);
  return 0;
}

int getMaxLengthExclude(char* *grid, int num_rows, int num_columns, int length, int row, int column) {
  int result = 0;

  for (int row_count = 0; row_count < num_rows; row_count++)
    for (int column_count = 0; column_count < num_columns; column_count++) {
      if (row_count == row && column_count == column) continue;

      int offset = 0;
      while (isValidPlus(grid, num_rows, num_columns, row_count, column_count, offset) &&
          !overlap(length, row, column, offset, row_count, column_count, num_rows, num_columns))
        offset++;

      int max = offset - 1;
      if (result < max)
        result = max;
    }

  return result;
}

int twoPluses(char* *grid, int num_rows, int num_columns) {
  int* *max_lengths = createGrid(num_rows, num_columns);
  int result = 0;

  for (int row_count = 0; row_count < num_rows; row_count++) {
    for (int column_count = 0; column_count < num_columns; column_count++) {
      if (grid[row_count][column_count] == 'B') continue;

      int offset = 0;
      while (isValidPlus(grid, num_rows, num_columns, row_count, column_count, offset)) {
        int next_max = getMaxLengthExclude(grid, num_rows, num_columns, offset, row_count, column_count);
        int product = (offset * 4 + 1) * (next_max * 4 + 1);

        if (product > result)
          result = product;

        offset++;
      };
    }
  }

  return result;
}

int main() {
  int num_rows, num_columns;
  scanf("%d %d", &num_rows, &num_columns);

  char* *grid = malloc(num_rows * sizeof(char*));
  for (int count = 0; count < num_rows; count++) {
    char *row = malloc((num_columns + 1) * sizeof(char));
    scanf("%s", row);
    grid[count] = row;
  }

  int result = twoPluses(grid, num_rows, num_columns);
  printf("%d\n", result);

  return 0;
}
