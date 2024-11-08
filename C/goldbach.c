#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
/*
Goldbach's conjecture states that every even natural
number greater than 2 is the sum of two prime numbers.

Given an even natural number greater than 2, find two
primes (*prime1) and (*prime2) such that
n = (*prime1) + (*prime2).
*/
void sum_of_two_primes(int n, int* prime1, int* prime2) {
  int a=n/2;
  while(!is_prime(a)||!is_prime(n-a)) a++;
  *prime1=a;
  *prime2=n-a;
}




bool is_prime(int n) {
    if (n <= 1) {
        return false;  
    }
    
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false; 
        }
    }

    return true;  
}
    

    
void TestCase1() {
  // Test case 1: 10 
  int prime1, prime2;
  sum_of_two_primes(10, &prime1, &prime2);
  assert(is_prime(prime1)&&is_prime(prime2)&&(prime1+prime2 == 10));
  printf("Passed TestCase1\n");
}

void TestCase2() {
  // Test case 2: 2828 
  int prime1, prime2;
  sum_of_two_primes(2828, &prime1, &prime2);
  assert(is_prime(prime1)&&is_prime(prime2)&&(prime1+prime2 == 2828));
  printf("Passed TestCase2\n");
}

void TestCase3() {
  // Test case 3: 82828
  int prime1, prime2;
  sum_of_two_primes(82828, &prime1, &prime2);
  assert(is_prime(prime1)&&is_prime(prime2)&&(prime1+prime2 == 82828));
  printf("Passed TestCase3\n");
}

int main() {
  TestCase1();
  TestCase2();
  TestCase3();
  return 0;
}