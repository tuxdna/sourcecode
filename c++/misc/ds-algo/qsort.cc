#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int myComparisonFunction(const void *x, const void *y) {
  return (strcmp(*(const char **)x, *(const char **)y));
}

int main(void) {
  char *data[10];
  unsigned int i, numStrings;

  // Read up to 100 character strings from standard input.

  for (i = 0; i < ((sizeof data) / (sizeof data[0])); i++) {
    if (1 != scanf("%as", &data[i])) {
      break;
    }
  }

  numStrings = i;

  printf ("%d strings found\n", numStrings);

  // Sort them alphabetically.

  qsort(data, numStrings, sizeof data[0],
        &myComparisonFunction);

  // Print them out, and free the memory malloc'ed by scanf.

  for (i = 0; i < numStrings; i++) {
    printf("data[%d] = \"%s\"\n", i, data[i]);
    free(data[i]);
  }
    
  return 0;

}
