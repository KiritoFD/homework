#include<stdio.h>
int main()
{
    printf("Enter 4 integers:");
    int a[4];
    for(int i=1;i<=4;i++) scanf("%d",&a[i-1]);
    int max=0,min=1000000;
    for(int i=0;i<4;i++)
    {
        if(a[i]>max) max=a[i];
        if(a[i]<min) min=a[i];
    }
    printf("The minimum is %d\n",min);
    printf("The maximum is %d",max);

}