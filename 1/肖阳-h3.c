#include<stdio.h>
int main()
{
    printf("Enter N:");
    int N,sum=0;scanf("%d",&N);
    for(int i=1;i<=N;i++) sum+=i*i;
    printf("%d",sum);
}