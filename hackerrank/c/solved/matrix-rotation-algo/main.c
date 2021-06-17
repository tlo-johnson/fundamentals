/*
 * num rotations to get back to original position = 2 * ((num rows - 1) + (num columns - 1))
 */

/*
 * attempt another rotate algorithm
 * create new grid. use indexes to figure out rotation
 * e.g. new_grid[1][1] = old_grid[1][2]
 */

/*
 * yet another idea, don't physically rotate the matrix
 * logically rotate it (i.e. move your pointers around the array instead of rotating the array)
 */

#include <stdio.h>
#include <stdlib.h>

void print(int rows, int columns, int* *matrix) {
  for (int row_count = 0; row_count < rows; row_count++) {
    for (int col_count = 0; col_count < columns; col_count++)
      printf("%d ", matrix[row_count][col_count]);
    puts("");
  }
}

void rotate(int rows, int columns, int* *matrix, int offset) {
  int rotate_rows = rows - (offset * 2);
  int rotate_columns = columns - (offset * 2);

  int temp = matrix[offset][offset];

  for (int count = 0; count < rotate_columns - 1; count++)
    matrix[offset][offset + count] = matrix[offset][offset + count + 1];
  matrix[offset][offset + rotate_columns - 1] = matrix[offset + 1][offset + rotate_columns - 1];

  for (int count = 0; count < rotate_rows - 1; count++)
    matrix[offset + count][offset + rotate_columns - 1] = matrix[offset + count + 1][offset + rotate_columns - 1];
  matrix[offset + rotate_rows - 1][offset + rotate_columns - 1] = matrix[offset + rotate_rows - 1][offset + rotate_columns - 2];

  for (int count = rotate_columns - 1; count > 0; count--)
    matrix[offset + rotate_rows - 1][offset + count] = matrix[offset + rotate_rows - 1][offset + count - 1];
  matrix[offset + rotate_rows - 1][offset] = matrix[offset + rotate_rows - 2][offset];

  for (int count = rotate_rows - 1; count > 0; count--)
    matrix[offset + count][offset] = matrix[offset + count - 1][offset];
  matrix[offset + 1][offset] = temp;
}

void performRotations(int rows, int columns, int* *matrix, int offset, long long num_rotations) {
  num_rotations %= 2 * ((rows - (offset * 2) - 1) + (columns - (offset * 2) - 1));
  for (int count = 0; count < num_rotations; count++)
    rotate(rows, columns, matrix, offset);
}

void matrixRotation(int rows, int columns, int* *matrix, long long num_rotations) {
  int offset = 0;
  while (offset < (rows / 2) && offset < (columns / 2)) {
    performRotations(rows, columns, matrix, offset, num_rotations);
    offset++;
  }
  print(rows, columns, matrix);
}

int main() {
  int rows, columns;
  long long num_rotations;
  scanf("%d %d %lld", &rows, &columns, &num_rotations);

  int* *matrix = malloc(rows * sizeof(int*));
  for (int row_count = 0; row_count < rows; row_count++) {
    matrix[row_count] = malloc(columns * sizeof(int));
    for (int col_count = 0; col_count < columns; col_count++) {
      scanf("%d", &matrix[row_count][col_count]);
    }
  }

  matrixRotation(rows, columns, matrix, num_rotations);
  return 0;
}
