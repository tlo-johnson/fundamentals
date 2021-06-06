#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fillBoard(char** grid, int grid_rows, int grid_columns) {
  for (int row_count = 0; row_count < grid_rows; row_count++) {
    for (int column_count = 0; column_count < grid_columns; column_count++)
      grid[row_count][column_count] = 'O';
    grid[row_count][grid_columns] = '\0';
  }
}

char** alternateBoard(char** grid, int grid_rows, int grid_columns) {
  char* *alternate_board = malloc(grid_rows * sizeof(char*));
  for (int count = 0; count < grid_rows; count++) {
    char *alternate_row = malloc((grid_columns + 1) * sizeof(char));
    alternate_board[count] = alternate_row;
  }
  fillBoard(alternate_board, grid_rows, grid_columns);

  for (int row_count = 0; row_count < grid_rows; row_count++)
    for (int column_count = 0; column_count < grid_columns; column_count++) {
      if (grid[row_count][column_count] == '.') continue;

      alternate_board[row_count][column_count] = '.';
      if (!(row_count == 0)) alternate_board[row_count - 1][column_count] = '.';
      if (!(row_count == grid_rows - 1)) alternate_board[row_count + 1][column_count] = '.';
      if (!(column_count == 0)) alternate_board[row_count][column_count - 1] = '.';
      if (!(column_count == grid_columns - 1)) alternate_board[row_count][column_count + 1] = '.';
    }

  return alternate_board;
}

char** bomberMan(int seconds, char** grid, int grid_rows, int grid_columns) {
  if (seconds < 2) return grid;

  if (seconds % 2 == 0) {
    fillBoard(grid, grid_rows, grid_columns);
    return grid;
  }

  char** settled_grid = alternateBoard(grid, grid_rows, grid_columns);
  char** alternate_grid = alternateBoard(settled_grid, grid_rows, grid_columns);

  return ((seconds - 1) % 4 == 0) ? alternate_grid : settled_grid;
}

int main() {
  int grid_rows, grid_columns, seconds;
  scanf("%d %d %d", &grid_rows, &grid_columns, &seconds);

  char* *grid = malloc(grid_rows * sizeof(char*));
  for (int count = 0; count < grid_rows; count++) {
    char *row = malloc((grid_columns + 1) * sizeof(char));
    scanf("%s", row);
    grid[count] = row;
  }

  grid = bomberMan(seconds, grid, grid_rows, grid_columns);
  for (int count = 0; count < grid_rows; count++)
    printf("%s\n", grid[count]);

  return 0;
}
