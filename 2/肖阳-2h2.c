#include<stdio.h>
#include<math.h>
int prime( int a)//质数返回0
{
    if(a<=0) return 1;
    int b=0;
    if(a==1) return 1;
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0) b=1;
    }
    return b;
}
int main()
{
    printf("Enter number n :");
    int n;scanf("%d",&n);
    if(prime(n)==0) printf("%d is a prime",n);
    else printf("%d is not a prime",n);
}