#include<stdio.h>
long long BinomialCoefficient(int n, int m) {
    long long ans,i;
    for( i=1;i<=m;i++) ans*=n+1-i;
    for( i=1;i<=m;i++) ans/=i;
    return ans;
}//c(n,m)=c(n-1,m-1)+c(n-1,m)
//choose m from n, c(n,m)=c(n-1,m-1)*n/(m-1)
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    printf("%lld",BinomialCoefficient(n,m));
}
