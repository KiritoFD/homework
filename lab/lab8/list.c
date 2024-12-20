#include <stdio.h>
#include <assert.h>
// Add a new element 'new_number' to a sorted list.
// And update the length of the list.
void insert(int* list, int* len, int new_number) {
  int i;
  for (i = 0; i <* len; i++) {
    if (list[i] >=new_number) break;
  }
  for (int j = *len; j > i; j--) {
    list[j] = list[j-1];
  }
  list[i] = new_number;
  *len += 1;
}

// Look for an element 'target' in the sorted list.
// If found, return its index; otherwise, return -1.
int search(int* list, int len, int target) {
  for (int i = 0; i < len; i++) {
    if (list[i] == target) return i;
  }
  return -1;
}

// Remove an element 'target' from the sorted list.
// If the target is found, update the length and
// return 1; otherwise, return 0.
int delete(int* list, int* len, int target) {
  int i;
  for (i = 0; i < *len; i++) {
    if (list[i] == target) break;
  }
  if (i == *len) return 0;
  for (int j = i; j < *len-1; j++) {
    list[j] = list[j+1];
  }
  *len -= 1;
  return 1;
}

void InsertTestCase() {
  // Insert test case : 
  int list[100] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  int len = 10;
  insert(list, &len, 30);
  assert(len == 11 && list[10] == 30);
  printf("Passed InsertCase1");
  insert(list, &len, 15);
  assert(len == 12 && list[6] == 15);
  printf("Passed InsertCase2");
  insert(list, &len, 1);
  assert(len == 13 && list[0] == 1);
  printf("Passed InsertCase3");
  printf("Passed All InsertTestCase1\n");
}

void SearchTestCase() {
  // Search test case : 
  int list[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  int len = 10;
  
  assert(search(list,len,2) == 0);
  printf("Passed SearchCase1");
  assert(search(list,len,15) == -1);
  printf("Passed SearchCase2");
  assert(search(list,len,29) == 9);
  printf("Passed SearchCase3");
  
  printf("Passed All SearchTestCase1\n");
}

void DeleteTestCase() {
  // Dlete test case : 
  int list[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  int len = 10;
  assert(delete(list, &len, 15) == 0 && len == 10);
  printf("Passed DeleteCase1");
  assert(delete(list, &len, 2) == 1 && len == 9 && list[0] == 3 && list[8] == 29 );
  printf("Passed DeleteCase2");
  assert(delete(list, &len, 17) == 1 && len == 8 && list[5] == 19 && list[7] == 29);
  printf("Passed DeleteCase3");
  printf("Passed All DeleteTestCase\n");
}

int main() {
  InsertTestCase();
  SearchTestCase();
  DeleteTestCase();
  return 0;
}