#include<stdio.h>
int main()
{
    printf("Input number n: ");
    int n;scanf("%d",&n);
    float min;
    float a;
    printf("Input %d real numbers: ",n);
    scanf("%f",&a);
    min=a;
    for(int i=1;i<n;i++){
        scanf("%f",&a);
        if(a<min) min=a;
    }
    printf("The minimum is %.2f",min);
}