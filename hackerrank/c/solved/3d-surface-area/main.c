/*
 * for each block, find length of sides contributing to surface area
 * (top, bottom, left, right, front, back)
 * top and bottom will always contribute 1 each. others will contribute if they are taller than neighbour
 *
 * sum all contributing edges
 */

#include <stdlib.h>
#include <stdio.h>

int surfaceArea(int num_rows, int num_columns, int* *board) {
  int surface_area = 0;

  for (int row_count = 0; row_count < num_rows; row_count++) {
    for (int col_count = 0; col_count < num_columns; col_count++) {
      int height = board[row_count][col_count];
      int top_surface_area = 1, bottom_surface_area = 1;
      int left_surface_area, right_surface_area, front_surface_area, back_surface_area;

      if (row_count == 0)
        left_surface_area = height;
      else {
        int block_to_left = board[row_count - 1][col_count];
        if (block_to_left >= height) left_surface_area = 0;
        else left_surface_area = height - block_to_left;
      }

      if (row_count == num_rows - 1)
        right_surface_area = height;
      else {
        int block_to_right = board[row_count + 1][col_count];
        if (block_to_right >= height) right_surface_area = 0;
        else right_surface_area = height - block_to_right;
      }

      if (col_count == 0)
        front_surface_area = height;
      else {
        int block_to_front = board[row_count][col_count - 1];
        if (block_to_front >= height) front_surface_area = 0;
        else front_surface_area = height - block_to_front;
      }

      if (col_count == num_columns - 1)
        back_surface_area = height;
      else {
        int block_to_back = board[row_count][col_count + 1];
        if (block_to_back >= height) back_surface_area = 0;
        else back_surface_area = height - block_to_back;
      }

      surface_area += top_surface_area + bottom_surface_area + left_surface_area +
        right_surface_area + front_surface_area + back_surface_area;
    }
  }

  return surface_area;
}

int main() {
  int num_rows, num_columns;
  scanf("%d %d", &num_rows, &num_columns);

  int* *board = malloc(num_rows * sizeof(int*));
  for (int count = 0; count < num_rows; count++) {
    int *row = malloc(num_columns * sizeof(int));
    for (int inner_count = 0; inner_count < num_columns; inner_count++)
      scanf("%d", row + inner_count);
    board[count] = row;
  }

  printf("%d", surfaceArea(num_rows, num_columns, board));
}
