#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define EPS 1e-4

int double_equal(double a, double b) {
    return fabs(a - b) < EPS;
}

// Calculate and return the arithmetic mean
// (average) of an array of doubles.
double arithmetic_mean(double *list, int len) {
  double mean=0;
  for(int i=0;i<len;i++) mean+=list[i];
  return mean/len;
  // WRITE YOUR CODE HERE
}

// Calculate and return the geometric mean
// of an array of doubles.
//
// The geometric mean of n numbers x1, x2, ..., xn
// is defined as (x1x2...xn)^(1/n).
double geometric_mean(double *list, int len) {
  long double sum=1.00;
  for(int i=0;i<len;i++){
    sum*=list[i];
  }
  return pow(sum,1.0/len);
  // WRITE YOUR CODE HERE
}

// Given an array of doubles of length len, compute
// the variance.
//
// The variance of n numbers x1, x2, ..., xn is
// defined as (1/n)*\sum_i (xi-m)^2, where m is the
// arithmetic mean of x1, ..., xn.
double variance(double *list, int len) {
  double mean=arithmetic_mean(list,len);
  double variance=0;
  for(int i=0;i<len;i++) variance+=(list[i]-mean)*(list[i]-mean);
  return variance/len;
  // WRITE YOUR CODE HERE
}

// Given an array of doubles of length len, compute
// the L^p norm.
//
// The L^p norm of n numbers x1, x2, ..., xn is
// defined as
//  (\sum_i |x_i|^p)^(1/p).
//
// For example, the Euclidean norm is the L^2 norm.
double Lp_norm(double *list, int len, double p) {
  double norm=0;
  for(int i=0;i<len;i++){
    norm+=pow(list[i],p);
  }
  return pow(norm,1.0/p);
  // WRITE YOUR CODE HERE
}

// Test case with a variety of inputs
void TestCase1() {
    int len = 5;
    double list[5] = {2, 3, 5, 7, 9};

    assert(double_equal(arithmetic_mean(list, len), 5.20) == 1);
    assert(double_equal(geometric_mean(list, len), 4.521602) == 1);
    assert(double_equal(variance(list, len), 6.56) == 1);
    assert(double_equal(Lp_norm(list, len, 2), 12.961481) == 1);
    assert(double_equal(Lp_norm(list, len, 3), 10.720217) == 1);
    assert(double_equal(Lp_norm(list, len, 4), 9.920046) == 1);

    printf("TestCase1 Passed\n");
}

// Test case with uniform numbers
void TestCase2() {
    int len = 4;
    double list[4] = {4, 4, 4, 4};

    assert(double_equal(arithmetic_mean(list, len), 4.0) == 1);
    assert(double_equal(geometric_mean(list, len), 4.0) == 1);
    assert(double_equal(variance(list, len), 0.0) == 1);
    assert(double_equal(Lp_norm(list, len, 2), 8.0) == 1);

    printf("TestCase2 Passed\n");
}

// Test case with one element
void TestCase3() {
    int len = 1;
    double list[1] = {10};

    assert(double_equal(arithmetic_mean(list, len), 10.0) == 1);
    assert(double_equal(geometric_mean(list, len), 10.0) == 1);
    assert(double_equal(variance(list, len), 0.0) == 1);
    assert(double_equal(Lp_norm(list, len, 2), 10.0) == 1);

    printf("TestCase3 Passed\n");
}

// Test case with zeros and positives
void TestCase4() {
    int len = 4;
    double list[4] = {0, 5, 0, 5};

    assert(double_equal(arithmetic_mean(list, len), 2.5) == 1);
    assert(double_equal(geometric_mean(list, len), 0.0) == 1); // Product includes 0
    assert(double_equal(variance(list, len), 6.25) == 1);
    assert(double_equal(Lp_norm(list, len, 1), 10.0) == 1);

    printf("TestCase4 Passed\n");
}

int main() {
    TestCase1();
    TestCase2();
    TestCase3();
    TestCase4();
    return 0;
}