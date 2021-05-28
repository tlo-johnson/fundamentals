#include <stdio.h>
#include <stdlib.h>

/*
 * +10 +10 +10 => a
 * +10 +10 +100 => b
 * +10 +100 +10 => b
 * +100 +10 +10 => b
 * +10 +100 +100 => c
 *
 * (n - 0)(a) + 0b, (n - 1)(a) + 1b, (n-2)a + 2b, (n-3)a + 3b, ..., n(b)
 * 30, 120, 210, 300
 */

/*
 * from discussion
 * similar to this solution. to go from lowest permutation (i.e. (n - 0)(a)) to highest permutation (i.e. n * b)
 * you are essentially subtracting a and adding b. so you can just calculate the lowest and highest permutations
 * and then add (b - a) over and over to get the values inbetween
 */

int* stones(int num_stones, int smaller_diff, int bigger_diff) {
  int* result = malloc(num_stones * sizeof(int));

  for (int count = 0; count < num_stones; count++) {
    int num = ((num_stones - 1 - count) * smaller_diff) + (count * bigger_diff);
    result[count] = num;
  }

  return result;
}

int main() {
  int num_test_cases;
  scanf("%d", &num_test_cases);

  for (int count = 0; count < num_test_cases; count++) {
    int num_stones, first_diff, second_diff;
    scanf("%d", &num_stones);
    scanf("%d", &first_diff);
    scanf("%d", &second_diff);
    int smaller_diff = first_diff < second_diff ? first_diff : second_diff;
    int bigger_diff = first_diff > second_diff ? first_diff : second_diff;

    int* result = stones(num_stones, smaller_diff, bigger_diff);
    if (first_diff == second_diff)
      printf("%d ", result[0]);
    else {
      for (int r_count = 0; r_count < num_stones; r_count++)
        printf("%d ", result[r_count]);
    }
    printf("\n");

    free(result);
  }

  return 0;
}
