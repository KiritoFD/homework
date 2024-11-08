#include <stdio.h>
#include <assert.h>

/*
Ramanujan number is the smallest positive integer, which can be
expressed as the sum of two cubic numbers in two different ways.
It is also known as the Hardy-Ramanujan number.

Find this number.
*/

// Return the Ramanujan number.
int ramanujan() {
  int i, j, k, l;
  for (i = 1; i < 100; i++) {
    for (j = i + 1; j < 100; j++) {
      for (k = j+1; k < 100; k++) {
        for (l =  1; l < 100; l++) {
          if (i * i * i + j * j * j == k * k * k + l * l * l) {
            return i * i * i + j * j * j;
         }
        }
      }
    }
  }
}

int main() {
  assert(ramanujan() == 1729);
  printf("Passed the test.\n");
  return 0;
}
