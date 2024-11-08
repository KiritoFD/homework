#include <stdio.h>
#include <assert.h>
int is_prime(int n) {
  int i;
  for (i=2; i*i<=n; i++) {
    if (n%i==0) return 0;
  }
  return 1;
}
/*
Use the Sieve of Eratosthenes to count the number of
primes between 1 and n.
*/

// Return the number of primes between [2, n], where
// n <= 10^8.
int count_prime(int n) {
  int i, count=0;
  for (i=2; i<=n; i++) {
    if (is_prime(i)) count++;
  }
  return count;
}
void TestCase1() {
  // Test Case 1: n:10000 result=1229
  int res;
  res=count_prime(10000);
  assert(res==1229);
  printf("Passed TestCase1\n");
}

void TestCase2() {
  // Test Case 2: n=99988865 result=5760854
  int res;
  res=count_prime(99988865);
  assert(res==5760854);
  printf("Passed TestCase2\n");
}

void TestCase3() {
  // Test Case 3: n=100 result=25
  int res;
  res=count_prime(100);
  assert(res==25);
  printf("Passed TestCase3\n");
}
int main() {
  TestCase1();
  TestCase2();
  TestCase3();
  return 0;
}
