#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// Given n and a list of n-1 distinct integers from the set {1, 2, ..., n},
// return the missing integer in the range [1, n] that is not present in the list
int find_missing_element(int n, int* list) {
    int q[100000000]={0};
    long int i;for(i=1;i<n;i++) q[list[i-1]-1]=1;
    for(i=0;i<n;i++) if(q[i]==0) return i+1;
}  
void TestCase1() {
  int n = 5;
  int list[4] = {1, 2, 3, 4};
  assert(find_missing_element(n, list) == 5);
  printf("Passed TestCase1\n");
}

void TestCase2() {
  int n = 6;
  int list[6] = {4, 1, 3, 2, 5};
  assert(find_missing_element(n, list) == 6);
  printf("Passed TestCase2\n");
}

void TestCase3() {
  int n = 1000000;
  int target = 165536;
  int* list = (int*) malloc((n-1) * sizeof(int));
  int j = 1;int i;
  for ( i = 0; i < n-1; i ++) {
  	if (j == target) {
  	  j ++;
  	}
  	list[i] = j++;
  }
  assert(find_missing_element(n, list) == target);
  printf("Passed TestCase3\n");
}

int main() {
  TestCase1();
  TestCase2();
  TestCase3();
  return 0;
}