#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 // submitted answer ... sort implemented in my own answer is too slow
    #include <math.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <assert.h>
    #include <limits.h>
    #include <stdbool.h>

    static int compare (void const *a, void const *b)
    {
      char const *const *pa = a;
      char const *const *pb = b;
      if(strlen(*pa) == strlen(*pb))
        return strcmp(*pa, *pb);
      return strlen(*pa) - strlen(*pb);
    }


    int main(){
      int nbr;
      scanf("%d", &nbr);
      char **tab = malloc(sizeof(char*) * nbr);
      char *str = (char*)malloc(sizeof(char) * 1000000);
      for(int i = 0; i < nbr; i++)
      {
        scanf("%s", str);
        tab[i] = malloc(sizeof(char) * (strlen(str) + 1));
        sprintf(tab[i],"%s",str);
      }
      qsort(tab, nbr, sizeof(char*), compare);
      for(int i = 0; i < nbr; i++)
        printf("%s\n", tab[i]);
      return 0;
    }
 */

int compare(char *num1, char *num2) {
  int length1 = strlen(num1);
  int length2 = strlen(num2);

  if (length1 < length2) return -1;
  if (length1 > length2) return 1;
  return strcmp(num1, num2);
}

int findInsertionIndex(char *num, char* *sorted, int left, int right) {
  if (left == right)
    return left;

  int mid = (left + right) / 2;
  int comparison = compare(sorted[mid], num);
  if (comparison == 0) return mid;
  return comparison > 0 ?
    findInsertionIndex(num, sorted, left, mid) :
    findInsertionIndex(num, sorted, mid + 1, right);
}

void insert(char *num, char* *sorted, int sorted_count) {
  if (sorted_count == 0) {
    sorted[0] = num;
    return;
  }

  int insertion_index = findInsertionIndex(num, sorted, 0, sorted_count);

  if (insertion_index == sorted_count) {
    sorted[insertion_index] = num;
    return;
  }

  char *next = sorted[insertion_index];
  char *curr = num;
  for (int count = insertion_index; count < sorted_count; count++) {
    next = sorted[count];
    sorted[count] = curr;
    curr = next;
  }
  sorted[sorted_count] = next;
}

char** bigSorting(int unsorted_count, char** unsorted) {
  char* *sorted = (char**) malloc(unsorted_count * sizeof(char*));

  for (int count = 0; count < unsorted_count; count++)
    insert(unsorted[count], sorted, count);

  return sorted;
}

int main() {
  int max_digits = 1000000;

  int nums_count;
  scanf("%d", &nums_count);

  char* *nums = (char**) malloc(nums_count * sizeof(char*));
  for (int count = 0; count < nums_count; count++) {
    char *temp = (char*) malloc(max_digits * sizeof(char));
    scanf("%s", temp);
    nums[count] = temp;
  }

  char* *sorted = bigSorting(nums_count, nums);

  for (int count = 0; count < nums_count; count++)
    puts(sorted[count]);

  return 0;
}
