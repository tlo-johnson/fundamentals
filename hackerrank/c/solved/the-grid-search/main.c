#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char isMatch(char* *grid, int start_row, int start_col, char* *pattern, int num_pattern_rows, int num_pattern_columns) {
  for (int row_index = 0; row_index < num_pattern_rows; row_index++) {
    for (int column_index = 0; column_index < num_pattern_columns; column_index++) {
      if (pattern[row_index][column_index] != grid[row_index + start_row][column_index + start_col])
        return 0;
    }
  }

  return 1;
}

char* gridSearch(int num_grid_rows, char* *grid, int num_pattern_rows, char* *pattern) {
  int num_grid_columns = strlen(grid[0]);
  int num_pattern_columns = strlen(pattern[0]);

  for (int row_count = 0; row_count < num_grid_rows - num_pattern_rows + 1; row_count++) {
    for (int col_count = 0; col_count < num_grid_columns - num_pattern_columns + 1; col_count++) {
      if (grid[row_count][col_count] != pattern[0][0]) continue;
      if (!isMatch(grid, row_count, col_count, pattern, num_pattern_rows, num_pattern_columns)) continue;
      return "YES";
    }
  }

  return "NO";
}

char** getGrid(int *num_grid_rows) {
  int num_rows, num_columns;
  scanf("%d %d", &num_rows, &num_columns);

  char* *grid = malloc(num_rows * sizeof(char*));
  for (int row_count = 0; row_count < num_rows; row_count++) {
    char* row = malloc(num_columns * sizeof(char) + 1);
    scanf("%s", row);
    grid[row_count] = row;
  }

  *num_grid_rows = num_rows;
  return grid;
}

int main() {
  int num_test_cases;
  scanf("%d", &num_test_cases);

  for (int count = 0; count < num_test_cases; count++) {
    int num_grid_rows;
    char* *grid = getGrid(&num_grid_rows);

    int num_pattern_rows;
    char* *pattern = getGrid(&num_pattern_rows);

    printf("%s\n", gridSearch(num_grid_rows, grid, num_pattern_rows, pattern));
  }
}
