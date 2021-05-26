#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** cavityMap(char* *grid, int size) {
  for (int r_count = 1; r_count < size - 1; r_count++) {
    for (int c_count = 1; c_count < size - 1; c_count++) {
    int val = grid[r_count][c_count] - '0';
    int top = grid[r_count - 1][c_count] - '0';
    int bottom = grid[r_count + 1][c_count] - '0';
    int left = grid[r_count][c_count - 1] - '0';
    int right = grid[r_count][c_count + 1] - '0';

    if (val > top && val > bottom && val > left && val > right)
      grid[r_count][c_count] = 'X';
    }
  }

  return grid;
}

int main() {
  int size;
  scanf("%d", &size);

  char* *grid = malloc(size * sizeof(char*));
  for (int count = 0; count < size; count++) {
    char *data = malloc(size * sizeof(char) + 1);
    scanf("%s", data);
    grid[count] = data;
  }

  grid = cavityMap(grid, size);
  for (int count = 0; count < size; count++)
    printf("%s\n", grid[count]);

  return 0;
}
