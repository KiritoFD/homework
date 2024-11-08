#include<stdio.h>
 int mySqrt(int x) {
    int i=1;
    while(i*i<x) i+=30;
    if(i*i==x) return i;
    else {
        while(i*i>x) i--;
        return i;
    }
}
int main(){
    int a;
    scanf("%d",&a);
    printf("%d",mySqrt(a));
}