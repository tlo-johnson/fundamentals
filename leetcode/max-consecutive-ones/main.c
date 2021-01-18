#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
  int max = 0;
  int count = 0;
  int currentlyCounting = 0;

  while (--numsSize >= 0) {
    int num = nums[numsSize];
    if (num == 1) {
      count++;
      currentlyCounting = 1;
    }
    else if (currentlyCounting) {
      if (count > max) max = count;
      count = currentlyCounting = 0;
    }
  }

  if (currentlyCounting && count > max) max = count;
  return max;
}

int main() {
  int nums[] = { 0, 0, 0, 0, 0, 0 };
  printf("max consecutive ones: %d\n", findMaxConsecutiveOnes(nums, sizeof(nums) / sizeof(int)));
  return 0;
}
