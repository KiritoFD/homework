#include<stdio.h>
#include<math.h>
double f(float x){
    return exp(x*x);
}
double Integral(double a, double b, double eps) {
    double last=-1,next=0,gap=0.1;double i;
    while(fabs(last-next)>=eps){
        last=next;
        next=0;
        i=a;
        while(i<b-gap){
            next+=f((i+i-gap)/2)*gap;
            i+=gap;
        }next+=f((i+b)/2)*(b-i);
        gap/=10;
    }return next;
}
int main()
{
    double a,b,eps;
    scanf("%lf%lf%lf",&a,&b,&eps);
    printf("%lf",Integral(a,b,eps));
}