#include <stdio.h>
#include <assert.h>
#include<stdlib.h>
// Implement selection sort or bubble sort.
// Given an array of integers, sort them in
// the increasing order.
int cmp(const void* first, const void* second) {
  int val_x = *(int*) first;
  int val_y = *(int*) second;
  if (val_x == val_y) {
    return 0;
  }
  return val_x < val_y ? -1 : 1;
}
void merge(int *list, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    // 拷贝数据到临时数组
    for (int i = 0; i < n1; i++) {
        leftArr[i] = list[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = list[mid + 1 + j];
    }

    // 合并两个临时数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            list[k] = leftArr[i];
            i++;
        } else {
            list[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // 复制剩余的元素
    while (i < n1) {
        list[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        list[k] = rightArr[j];
        j++;
        k++;
    }
}
void mergeSort(int *list, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(list, left, mid);
            mergeSort(list, mid + 1, right);
            merge(list, left, mid, right);
        }
    }
void sort(int *list, int len) {
    // 辅助递归函数
    

    mergeSort(list, 0, len - 1);
}

void TestSort3() {
  int list[3] = {4, 1, 0};
  sort(list, 3);
  assert(list[0] == 0);
  assert(list[1] == 1);
  assert(list[2] == 4);
  printf("Passed Test Case 1\n"); 
}



// Generate n random integers as a test case.
void TestSortWithSize(int n, int test_case_number) {
  int list[n], list_cpy[n];
  int i;
  for (i = 0; i < n; i ++) {
    list[i] = rand(); 
    list_cpy[i] = list[i];
  }
  qsort(list_cpy, n, sizeof(int), cmp);
  sort(list, n);
  // Compare if two arrays are equal.
  for (i = 0; i < n; i ++) {
    assert(list[i] == list_cpy[i]);
  }
  printf("Passed Test Case %d\n", test_case_number); 
}

int main() {
  TestSort3();
  TestSortWithSize(10, 2);
  TestSortWithSize(100, 3);
  TestSortWithSize(1000, 4);
  TestSortWithSize(10000, 5);
  return 0;
}