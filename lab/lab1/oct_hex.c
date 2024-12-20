#include <stdio.h>

int main() {
  /* Input an integer N. Print its 
     octal and hexadecimal representations.
     E.g.
     Input: 77
     Ouput: 4d 115
  */
 int N;
 scanf("%d",&N);
 printf("%x %o",N,N);
  return 1;
}