#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

/*
 * num cities: 100
 * [0, 4, 8]
 *
 * max distances: 0 - 4, 4 - 8, 8 - 100
 */

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, int c_count, int* c) {
  char* cities = calloc(n, sizeof(char));

  for (int index = 0; index < c_count; index++) {
    int space_station = c[index];
    cities[space_station] = 1;
  }

  int max_distance = 0;
  for (int index = 0; index < n; index++) {
    int city = cities[index];
    if (city == 0) continue;

    int previous_city = index - 1;
    for (; previous_city >= 0; previous_city--)
      if (cities[previous_city] == 1)
        break;

    if (previous_city == -1) {
      max_distance = index;
      continue;
    }

    int distance = ((previous_city + index) / 2) - previous_city;
    if (distance > max_distance) max_distance = distance;
  }

  int previous_city = -1;
  for (int index = n - 1; index >= 0; index--)
    if (cities[index] == 1) {
      previous_city = index;
      break;
    }

  int distance_to_last_city = n - 1 - previous_city;
  if (distance_to_last_city > max_distance)
    max_distance = distance_to_last_city;

  free(cities);
  return max_distance;
}

int main()
{
    char** nm = split_string(readline());

    char* n_endptr;
    char* n_str = nm[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* m_endptr;
    char* m_str = nm[1];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char** c_temp = split_string(readline());

    int* c = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        char* c_item_endptr;
        char* c_item_str = *(c_temp + i);
        int c_item = strtol(c_item_str, &c_item_endptr, 10);

        if (c_item_endptr == c_item_str || *c_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(c + i) = c_item;
    }

    int c_count = m;

    int result = flatlandSpaceStations(n, c_count, c);

    printf("%d\n", result);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
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
