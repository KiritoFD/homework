#include<stdio.h>
#include<math.h>
double f(float x){
    return exp(x*x);
}
double Integral(double a, double b, double eps) {
    double last=-1,next=0,gap=0.1;
    while(fabs(last-next)>=eps){
        last=next;
        next=0;
        for(double a1=a+gap;a1<b-gap;a1+=gap){
            next+=f((a+a-gap)/2)*gap;
        }next+=f((a+b)/2)*(b-a);
        gap/=10;
    }return next;
}//积分函数
int main()
{
    double a,b,eps;
    scanf("%lf%lf%lf",&a,&b,&eps);
    printf("%lf",Integral(a,b,eps));
}