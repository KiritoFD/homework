#include <stdio.h>
#include <stdlib.h>
long long n = 1000000000;
int main() {
  // 1. Dynamically create an int type array of length n, where
  //    n = 1000 000 000.
  // 2. Set all elements of the array to the constant 1.
  // 3. Free the array at the end.
  int *array=(int *)malloc(sizeof(int)*n);
  for(int i=1;i<=n;i++) array[i-1]=1;
  free(array);
  return 0;
}