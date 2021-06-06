#include <stdlib.h>
#include <stdio.h>

int* absolutePermutation(int num_nums, int diff) {
  int *result = malloc(num_nums * sizeof(int) + 1);
  int *impossible = malloc(sizeof(int));
  impossible[0] = -1;

  if (diff == 0) {
    for (int count = 1; count <= num_nums; count++)
      result[count] = count;
    free(impossible);
    return result;
  }

  int *available = malloc((num_nums + 1) * sizeof(int));
  for (int count = 1; count <= num_nums; count++)
    available[count] = 1;

  int count = 1;
  while (count <= diff) {
    int val = count + diff;
    if (val > num_nums || available[val] == 0) {
      free(result);
      free(available);
      return impossible;
    }
    result[count++] = val;
    available[val] = 0;
  }

  count = num_nums;
  while (count > num_nums - diff) {
    int val = count - diff;
    if (available[val] == 0) {
      free(result);
      free(available);
      return impossible;
    }
    result[count--] = val;
    available[val] = 0;
  }

  for (int count = diff + 1; count < num_nums - diff + 1; count++) {
    int lower = count - diff;
    int higher = count + diff;
    if (available[lower] == 0 && available[higher] == 0) {
      free(result);
      free(available);
      return impossible;
    }

    if (available[lower] == 0) {
      result[count] = higher;
      available[higher] = 0;
    } else {
      result[count] = lower;
      available[lower] = 0;
    }
  }

  free(impossible);
  free(available);
  return result;
}

int main() {
  int num_queries;
  scanf("%d", &num_queries);

  for (int count = 0; count < num_queries; count++) {
    int num_nums, diff;
    scanf("%d %d", &num_nums, &diff);

    int *result = absolutePermutation(num_nums, diff);
    if (*result == -1) {
      puts("-1");
      free(result);
      continue;
    }

    for (int count = 1; count <= num_nums; count++)
      printf("%d ", result[count]);
    puts("");
    free(result);
  }
}
