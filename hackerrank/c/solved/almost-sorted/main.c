#include <stdio.h>
#include <stdlib.h>

int isSorted(int arr_length, int *arr) {
  for (int index = 0; index < arr_length - 1; index++) {
    if (arr[index] < arr[index + 1]) continue;
    return 0;
  }

  puts("yes");
  return 1;
}

void swap(int *arr, int start_index, int end_index) {
  int temp = arr[start_index];
  arr[start_index] = arr[end_index];
  arr[end_index] = temp;
}

int isSwappable(int arr_length, int *arr) {
  int count = 0, start_index, end_index;

  for (int index = 0; index < arr_length - 1; index++) {
    if (arr[index] < arr[index + 1]) continue;
    if (count > 1) return 0;
    if (count == 0) {
      start_index = index;
      end_index = index + 1;
    }
    else end_index = index + 1;

    count++;
  }

  swap(arr, start_index, end_index);
  if (!isSorted(arr_length, arr)) {
    swap(arr, start_index, end_index);
    return 0;
  }

  printf("swap %d %d\n", start_index + 1, end_index + 1);
  return 1;
}

int isReversable(int arr_length, int *arr) {
  int count = 0, start_index, end_index;

  for (int index = 0; index < arr_length - 1; index++) {
    if (arr[index] < arr[index + 1]) continue;
    if (count != 0) return 0;

    start_index = index;
    end_index = arr_length - 1;
    count++;

    for (int inner_index = index + 1; inner_index < arr_length; inner_index++) {
      if (arr[inner_index] > arr[inner_index + 1]) continue;
      end_index = inner_index;
      index = inner_index;
      count++;
      break;
    }
  }

  if (!(arr[start_index] < arr[end_index + 1] &&
      arr[end_index] > arr[start_index - 1]))
    return 0;

  printf("yes\nreverse %d %d\n", start_index + 1, end_index + 1);
  return 1;
}

void almostSorted(int arr_length, int *arr) {
  if (isSorted(arr_length, arr)) return;
  if (isSwappable(arr_length, arr)) return;
  if (isReversable(arr_length, arr)) return;
  puts("no");
}

int main() {
  int arr_length;
  scanf("%d", &arr_length);

  int *arr = malloc(arr_length * sizeof(int));
  for (int count = 0; count < arr_length; count++)
    scanf("%d", arr + count);

  almostSorted(arr_length, arr);
  return 0;
}
