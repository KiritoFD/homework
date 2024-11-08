#include <stdio.h>

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
  double pi=1.00;int i=2;
  while(PI-pi>=1e-3){
    pi+=1/(i*i);
  }
  printf("%lf",pi);
  return 0;
}