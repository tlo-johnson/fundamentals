#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
  int max = 0;
  int count = 0;

  while (--numsSize >= 0) {
    if (nums[numsSize] == 1) {
      count++;
    }
    else {
      count = 0;
    }

    if (count > max) max = count;
  }

  return max;
}

int main() {
  int nums[] = { 1, 1, 1, 1, 0, 0 };
  printf("max consecutive ones: %d\n", findMaxConsecutiveOnes(nums, sizeof(nums) / sizeof(int)));
  return 0;
}
