#include <stdio.h>
#include <math.h>
#include <assert.h>
#include<stdlib.h>
int cmp(const void* a, const void* b) {
    return *(int*)b-  *(int*)a;
}
void sum_of_squares(int n, int* k, int* list) {
    int a, b, c, d;
    for (a = 0; a * a <= n; a++) {
        for (b = a; a * a + b * b <= n; b++) {
            for (c = b; a * a + b * b + c * c <= n; c++) {
                for (d = c; a * a + b * b + c * c + d * d <= n; d++) {
                    if (a * a + b * b + c * c + d * d == n) {
                        list[0] = a;
                        list[1] = b;
                        list[2] = c;
                        list[3] = d;
                        qsort(list, 4, sizeof(int), cmp);
                        *k = (a > 0) + (b > 0) + (c > 0) + (d > 0);
                        return;
                    }
                }
            }
        }
    }
}

void TestCase1() {
    int k;
    int list[4];
    sum_of_squares(99999, &k, list);
    assert(k == 4);
    int i,sumOfSquares = 0;
    for ( i = 0; i < k; i++) {
        sumOfSquares += list[i] * list[i];
    }
    assert(sumOfSquares == 99999);
    printf("Passed TestCase1\n");
}

void TestCase2() {
    int k;
    int list[4];
    sum_of_squares(87352, &k, list);
    assert(k == 3);
    int i,sumOfSquares = 0;
    for ( i = 0; i < k; i++) {
        sumOfSquares += list[i] * list[i];
    }
    assert(sumOfSquares == 87352);
    printf("Passed TestCase2\n");
}

void TestCase3() {
    int k;
    int list[4];
    sum_of_squares(57, &k, list);
    assert(k == 3);
    int i,sumOfSquares = 0;
    for ( i = 0; i < k; i++) {
        sumOfSquares += list[i] * list[i];
    }
    assert(sumOfSquares == 57);
    printf("Passed TestCase3\n");
}

int main() {
    TestCase1();
    TestCase2();
    TestCase3();
    return 0;
}