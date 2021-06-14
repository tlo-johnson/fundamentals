// https://www.youtube.com/watch?v=-9PKZ8XkVBg&t=14s

#include <stdio.h>
#include <stdlib.h>

char* larrysArray(int length, int *arr) {
  int total_parity = 0;
  int max_num_seen = 0;
  for (int index = 0; index < length; index++)
    for (int count = index + 1; count < length; count++)
      if (arr[count] < arr[index])
        total_parity++;

  return total_parity % 2 == 0 ? "YES" : "NO";
}

int main() {
  int num_tests;
  scanf("%d", &num_tests);

  for (int count = 0; count < num_tests; count++) {
    int length;
    scanf("%d", &length);

    int *arr = malloc(length * sizeof(int));
    for (int arr_count = 0; arr_count < length; arr_count++)
      scanf("%d", arr + arr_count);

    printf("%s\n", larrysArray(length, arr));
    free(arr);
  }

  return 0;
}
