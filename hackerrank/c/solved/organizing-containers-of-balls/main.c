#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'organizingContainers' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts 2D_INTEGER_ARRAY container as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */

/*
 *  algo:
 *  decide on a pivot. sum of other nums in row must equal sum of other nums in column.
 *  possible if above constraint is satisfied for one pivot in every row, where two pivots can't be in the same column
 *
 */

/*
 * discussion points
 *
 * Only after re-reading my code, I realised that the variable M is not used at all(Edit-removing it now). LOL. Anyway array a[] stores the number of balls in each container. Array b[] stores the number of balls in each type. The number of balls in each container will be intact no matter how many swaps we do because of +1 -1. So all we need to check is that if there are any type of balls with the same quantity of that of each box. So after some swaps we can store all those balls in that container. Similarly for all containers. We should also note that once a ball kind is mapped to a container, we should not consider it again so I swapped it to the ith position and each time I am starting the inner loop from 'i'. In case no match is found, inner loop runs fully and j==n. So I break and print 'Impossible', else 'Possible'
 *
 * int n = in.nextInt();
 * int[] a = new int[n];
 * int[] b = new int[n];
 * for(int i=0; i<n; i++)
 * {
 *   for(int j=0; j<n; j++)
 *   {
 *     int x = in.nextInt();
 *     a[i] += x;
 *     b[j] += x;
 *   }
 * }
 * String pts = "Possible";
 * for(int i=0;i<n;i++)
 * {
 *   int j=0;
 *   for(j=i;j<n;j++)
 *   {
 *     if(a[i] == b[j])
 *     {
 *       int temp = b[j];
 *       b[j] = b[i];
 *       b[i] = temp;
 *       break;
 *     }
 *   }
 *   if(j==n)
 *   {
 *     pts = "Impossible";
 *     break;
 *   }
 * }
 * System.out.println(pts);
 */

char* organizingContainers(int container_rows, int container_columns, int** container) {
  // this code can be drastically simplified while maintaining the same logic. see java solution for example.
  int* row_sums = calloc(container_rows, sizeof(int));
  int* column_sums = calloc(container_columns, sizeof(int));
  int* used_columns = calloc(container_columns, sizeof(int));

  for (int row_index = 0; row_index < container_rows; row_index++) {
    for (int column_index = 0; column_index < container_columns; column_index++) {
      row_sums[row_index] += container[row_index][column_index];
      column_sums[column_index] += container[row_index][column_index];
    }
  }

  for (int row_index = 0; row_index < container_rows; row_index++) {
    for (int column_index = 0; column_index < container_columns; column_index++) {
      if (used_columns[column_index] != 0) continue;

      int val = container[row_index][column_index];
      if (row_sums[row_index] - val != column_sums[column_index] - val) continue;

      used_columns[column_index] = 1;
      break;
    }
  }

  for (int index = 0; index < container_columns; index++)
    if (used_columns[index] == 0)
      return "Impossible";

  return "Possible";
}

int main()
{
    int q = parse_int(ltrim(rtrim(readline())));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n = parse_int(ltrim(rtrim(readline())));

        int** container = malloc(n * sizeof(int*));

        for (int i = 0; i < n; i++) {
            *(container + i) = malloc(n * (sizeof(int)));

            char** container_item_temp = split_string(rtrim(readline()));

            for (int j = 0; j < n; j++) {
                int container_item = parse_int(*(container_item_temp + j));

                *(*(container + i) + j) = container_item;
            }
        }

        char* result = organizingContainers(n, n, container);

        printf("%s\n", result);
    }

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}
