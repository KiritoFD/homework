#include<stdio.h>
#include<math.h>
double f(double c0,double c1,double c2,double x){
    return (((x+c0)*x+c1)*x+c2)*x;
}//减小误差的秦九韶算法
double solve(double eps,double c0,double c1,double c2){
    double low=0,top=1.00,x=0.5;
    while(f(c0,c1,c2,low)*f(c0,c1,c2,top)>0){
        low--;
        top++;
    }
    while(top-low>eps){
        if(f(c0,c1,c2,x)==0) return x;
        if(f(c0,c1,c2,x)*f(c0,c1,c2,low)<0) low=x;
        else top=x;
        x=(low+top)/2;
    }
    return x;
}

int main()
{
    int a,b,j;j=2;
    printf("%d",(j+=1)*(j+1));
}