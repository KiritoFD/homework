#include<stdio.h>
int main()
{
    printf("Enter a number n: ");
    int size;scanf("%d",&size);
    int sum=0,num;
    printf("Input %d numbers: ",size);
    for(int i=1;i<=size;i++){
        scanf("%d",&num);
        sum+=num;
    }
    printf("The sum is %d",sum);
}