#include <stdio.h>
#include <assert.h>

// Given a specific date (year, month, day), this function
// and returns the total number of days that have passed
// since January 1st, Year 1.
// if date is illegal,return -1. 
int lunar(int x){
  int a=1;
  if(x%4==0) a*=-1;
	if(x%100==0) a*=-1;
	if(x%400==0) a=-1;
  return a;
}
int date_to_days(int year, int month, int day) {
  int days;
  int i;
  int leap=0;
  int monthdays[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  if(lunar(year)==-1) monthdays[1]=29;
  if(day>monthdays[month-1]) return -1;
int re=(year-1)*365;
  for( i=1;i<=year;i++){
    if(lunar(i)==-1) re++;
  }
  for( i=1;i<month;i++){
    re+=monthdays[i-1];
  }re+=day;
  return re-2;
  
}

void TestCase1() {
  // Test Case 1: 2016.2.29
  int days;
  days=date_to_days(2016,2,29);
  assert(days==736022);
  printf("Passed TestCase1\n");
}

void TestCase2() {
  // Test Case 1: 2017.2.29
  int days;
  days=date_to_days(2017,2,29);
  assert(days==-1);
  printf("Passed TestCase2\n");
}

void TestCase3() {
  // Test Case 3: 2024.10.12
  int days;
  days=date_to_days(2024,10,12);
  assert(days==739170);
  printf("Passed TestCase3\n");
}




int main() {
  TestCase1();
  TestCase2();
  TestCase3();
  return 0;
}
