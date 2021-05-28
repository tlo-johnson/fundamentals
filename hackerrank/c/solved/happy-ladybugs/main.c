#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * no if:
 *  - no holes and ladybugs are not all happy
 *  - there isn't at least 2 of each color of ladybug
 *
 * yes otherwise
 */

char* happyLadybugs(char *cells) {
  int max_types = 26;
  int length = strlen(cells), num_holes = 0;
  int *types = calloc(max_types, sizeof(int));

  for (int count = 0; count < length; count++) {
    if (cells[count] == '_') {
      num_holes++;
      continue;
    }

    int index = cells[count] - 'A';
    types[index]++;
  }

  if (num_holes == 0) {
    for (int count = 0; count < length; count++) {
      if (count == 0 && cells[count] != cells[count + 1])
        return "NO";
      else if (count == length - 1 && cells[count] != cells[count - 1])
        return "NO";
      else if (cells[count] != cells[count - 1] && cells[count] != cells[count + 1])
        return "NO";
    }

    return "YES";
  }

  for (int index = 0; index < max_types; index++)
    if (types[index] == 1)
      return "NO";

  return "YES";
}

int main() {
  int num_games;
  scanf("%d", &num_games);

  for (int count = 0; count < num_games; count++) {
    int num_cells;
    scanf("%d", &num_cells);

    char *cells = malloc(num_cells * sizeof(char) + 1);
    scanf("%s", cells);

    printf("%s\n", happyLadybugs(cells));
    free(cells);
  }

  return 0;
}
