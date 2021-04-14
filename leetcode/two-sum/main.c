#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  int* result = malloc(sizeof(int[2]));
  *returnSize = 2;

  for(int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if (!(nums[i] + nums[j] == target)) continue;

      result[0] = i;
      result[1] = j;
      return result;
    }
  }

  return NULL;
}

int main() {
  int nums[] = { 2, 7, 11, 15};
  int numsSize = sizeof nums / sizeof *nums;
  int target = 18;
  int returnSize[] = {2};

  int* result = twoSum(nums, numsSize, target, returnSize);
  printf("%d, %d", result[0], result[1]);
  free(result);
}
