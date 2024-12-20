#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <iostream>
void sum_of_squares(int n, int* k, int* list) {
    int min_k = 5;  // 初始设一个大于4的值，方便后续比较找到更小的k
    int temp_list[4];  // 临时用来存储不同组合情况的数组
    int a, b, c, d;
    // 尝试找到所有可能的组合情况（k从1到4）
    for (a = (int)sqrt(n/4); a >= 0; a--) {  // 从大到小遍历a
        if(a*a==n){
            list[0]=a;
            min_k = 1;
            continue;
        }
        for (b = (int)sqrt((n - a * a)/3); b >= a; b--) {  // 根据a的值限定b的范围并从大到小遍历
            if(a*a+b*b==n){
                temp_list[0]=a;
                temp_list[1]=b;
                if (2 < min_k) {  // 如果当前找到的k（这里是2）比min_k小，更新min_k和list
                    min_k = 2;
                    for (int i = 0; i < 2; i++) {
                        list[i] = temp_list[i];
                    }
                }
                continue;
            }
            for (c = (int)sqrt(n - a * a - b * b); c >= b; c--) {  // 根据a、b的值限定c的范围并从大到小遍历
                if (a * a + b * b + c * c == n) {
                    temp_list[0] = a;
                    temp_list[1] = b;
                    temp_list[2] = c;
                    if (3 < min_k) {
                        min_k = 3;
                        for (int i = 0; i < 3; i++) {
                            list[i] = temp_list[i];
                        }
                    }
                    continue;
                }
                // 剪枝判断，若当前部分和加上最大可能平方数都小于n，跳过此分支
                if (a * a + b * b + c * c + (int)sqrt(n - a * a - b * b - c * c) * (int)sqrt(n - a * a - b * b - c * c) < n) {
                    continue;
                }
                for (d = (int)sqrt(n - a * a - b * b - c * c); d >= c; d--) {
                    if (a * a + b * b + c * c + d * d == n) {
                        temp_list[0] = a;
                        temp_list[1] = b;
                        temp_list[2] = c;
                        temp_list[3] = d;
                        if (4 < min_k) {
                            min_k = 4;
                            for (int i = 0; i < 4; i++) {
                                list[i] = temp_list[i];
                            }
                        }
                    }
                }
            }
        }
    }
    *k = min_k;
    return;
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