#include <stdio.h>
#include <stdlib.h>

int introTutorial(int val, int arr_count, int *arr) {
  for (int count = 0; count < arr_count; count++)
    if (arr[count] == val)
      return count;

  exit(1);
}

int main() {
  int val;
  scanf("%d", &val);

  int arr_count;
  scanf("%d", &arr_count);

  int *arr = (int *) malloc(arr_count * sizeof(int));
  for (int count = 0; count < arr_count; count++)
    scanf("%d", arr + count);

  int result = introTutorial(val, arr_count, arr);
  printf("%d\n", result);

  return 0;
}
