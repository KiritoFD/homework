#include <stdio.h>
#include <math.h>
#include <assert.h>

#define EPS 1e-4

int double_equal(double a, double b) {
    return fabs(a - b) < EPS/10;
}

/*
Given a continuous function f:R->R, and an interval [left, right],
find 'total' solutions in [left, right], and store them in a
list in increasing order.

Return 1 if we manage to find 'total' solutions; return 0 otherwise.
*/
int solve_equation(double (*f)(double), double left, double right,
  int total, double* list) {
    int count = 0;
    for (double x = left; x <= right; x += EPS/100) {
        if (double_equal(f(x), 0.0)) {
            list[count] = x;
            count++;
            printf("%lf\n", x);
            x+=0.1;
        }
    }//count--;
    return count == total;
}

double f1(double x) {                                                 
    return sin(x);
}

double f2(double x) {
    return x*x*x - 2*x*x - 4*x + 3;
}

double f3(double x) {
    return exp(sin(x)) - x;
}

void TestCase1() {
    double list[10];
    assert(solve_equation(f1, 0, 10, 4, list) == 1);
    int i;
    for (i = 0; i < 4; i++) {
        assert(double_equal(f1(list[i]), 0.0));
    }

    printf("TestCase1 passed!\n");
}

void TestCase2() {
    double list[10];
    assert(solve_equation(f2, -2, 4, 3, list) == 1);
    int i;
    for (i = 0; i < 3; i++) {
        assert(double_equal(f2(list[i]), 0.0));
    }

    printf("TestCase2 passed!\n");
}

void TestCase3() {
    double list[10];
    assert(solve_equation(f3, 2, 4, 2, list) == 0);
    assert(solve_equation(f3, 2, 4, 1, list) == 1);
    assert(double_equal(f3(list[0]), 0.0));

    printf("TestCase3 passed!\n");
}

int main() {
    TestCase1();
    TestCase2();
    TestCase3();
    return 0;
}