#include <stdio.h>
#include<math.h>
#include<stdlib.h>
/*
Sample a random point (x, y) in the square [-1, 1] * [-1, 1].
There is a unit circle C centered on (0, 0) with a radius of 1.
The probability that a randomly chosen point falls inside
the circle C is exactly PI / 4.

Estimate the value of PI with a precision of 1e-3 by sampling
a sufficient number of points.
*/
double randf() {
    return (double)rand() / RAND_MAX;
}
int main() {
    const double PI=3.1415926535284;
    int count=0,time=0;
    double pi;
    double a,b;
    while(fabs(PI-pi)>=1e-10){
        a=randf();
        b=randf();
        if(a*a+b*b<=1.00) count++;
        time++;
        printf("%d %d ",count,time);
        pi=(double)count/time*4;
        printf("%lf\n",pi);
    }
    printf("%lf %d",pi,time);
  return 0;
}