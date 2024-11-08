#include <stdio.h>
#include<math.h>
/*
Let zeta(s) = 1/1^s + 1/2^s + 1/3^s + ...
It is known that
  zeta(2) = PI^2 / 6
  zeta(4) = PI^4 / 90

The goal is to compute the constant PI to a precision of 1e-3
(meaning three decimal places) using the Riemann zeta function.
*/

int main() {
  const double PI=3.1415926535;
  double pi1=1.00,i=2.00;
  double pi=sqrt(6.00*pi1);
  while(PI-pi>=1e-3){
    pi1+=1/(i*i);
    i+=1.00;
     pi=sqrt(6.00*pi1);
    printf("%lf ",pi);
  }
  printf("%lf",pi);
  return 0;
}