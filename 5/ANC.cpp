#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <iostream>
int compare(const void*a,const void*b){
    const int *a1=(const int *)a;
    const int *b1=(const int *)b;
    if(*a1<*b1) return 1;
    if(*a1==*b1) return 0;
    if(*a1>*b1) return -1;
    }
/* Given a positive integer n, write n as a sum of k squares,
where k <= 4, that is, n = a1^2 + ... + ak^2, making k 
as small as possible.
*/
void sum_of_squares(int n, int* k, int* list) {
    int a, b, c, d;
    for (a = 0; a * a <= n; a++) {
        if(a*a==n){
            list[0]=a;
            *k=1;
            return;
        }
        for (b = a; a * a + b * b <= n; b++) {
          if(a*a+b*b==n){
            list[0]=a;
            list[1]=b;
            *k=2;
            return;
          }
            for (c = b; a * a + b * b + c * c <= n; c++) {
                if (a * a + b * b + c * c == n) {
                    list[0] = a;
                    list[1] = b;
                    list[2] = c;
                    *k = 3;
                    return;
                }
                for (d = c; a * a + b * b + c * c + d * d <= n; d++) {
                    if (a * a + b * b + c * c + d * d == n) {
                        list[0] = a;
                        list[1] = b;
                        list[2] = c;
                        list[3] = d;
                        *k = 4;
                        qsort(list, k, sizeof(int)*4,cmp);
                        *k=(a>0)+(b>0)+(c>0)+(d>0);
                        return;
                    }
                }
            }
        }
    }
}
  
void TestCase1() {
  // Test Case 1: 99999
  int k ;
  int list[4] ;
  sum_of_squares(99999, &k, list);
  assert(k == 4);
  int sumOfSquares = 0;
  for(int i = 0; i < k ; i++){
    sumOfSquares += list[i]*list[i];
  }
  assert(sumOfSquares == 99999);
  printf("Passed TestCase1\n");
}

void TestCase2() {
  // Test Case 1: 87352
  int k ;
  int list[4] ;
  sum_of_squares(87352, &k, list);
  cout<<k;

  assert(k == 3);
  int sumOfSquares = 0;
  for(int i = 0; i < k ; i++){
    sumOfSquares += list[i]*list[i];
  }
  assert(sumOfSquares == 87352);
  printf("Passed TestCase2\n");
}

void TestCase3() {
  // Test Case 3: 57
  int k ;
  int list[4] ;
  sum_of_squares(57, &k, list);
  assert(k == 3);
  int sumOfSquares = 0;
  for(int i = 0; i < k ; i++){
    sumOfSquares += list[i]*list[i];
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