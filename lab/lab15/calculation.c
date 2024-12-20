#include <stdio.h>
#include<math.h>
int x,y,z;
//sqrt():
//fabs(float)
//pow(double,double)
//sin(double),cos(double),tan(double)
//asin(double),acos(double),atan(double);arc,actually.
int max(int a,int b){
    return a>b?a:b;
    //三目运算符:condition?return_if_true:return_if_false;
    return a>b?a:b+1;
    return ((a>b)?a:(b+1));
    //条件运算从右往左计算，所以先计算b+1，再判断a>b。
    return  a>b?2:3.5;//c的类型是double。:
    //类型低的表达式会自动转换为类型高的表达式的类型。
    //auto声明变量的类型，但不能初始化。
}
void swap(int *a,int *b){
    int a1=*a,b1=*b;
    a1^=b1^=a1^=b1;
    *a=b1;
    *b=a1;
    //异或运算：a^b^a^b=b,a^b=a,a=b。
}//a^=b^=a^=b,交换a和b的值。
// >>n:右移n位,乘以2的n次方;
//<<n:左移n位,除以2的n次方。
int doubleEqual(double a,double b){
    return fabs(a-b)<1e-6;
}//判断两个double是否相等;
//不能用==,因为double的精度问题。
double f(int a,int x,int y,int z){
    return x*pow(a,2)+y*a+z;
}
int main(){
//单目运算符：+(positive),-(negative)
//双目运算符：+,-,*,/,%(modulus),>(greater than),<(less than),>=,<=,==,!=(not equal)
// int a=-5/3;//a=-1,向0取整
// int b=5%2;//b=1,取余数
// int c=5+3*2;//c=11,运算顺序从左到右
// int d=5-3/2;//d=2,运算顺序从左到右
// int i,j;
// i = 4;
// j = ++i; 		//  i结果为5，j的结果为5
// i = 4;
// j = i++;		//  i结果为5，j的结果为4
// i = 4;
// j = --i; 		//  i结果为3，j的结果为3
// i = 4;
// j = i--;		//  i结果为3，j的结果为4
//二分：
// scanf("%d%d%d",x,y,z);
// double left=0,right=10,mid;
// while(f(left)*f(right)>0) right++;
// while(right-left>1e-6){
//     mid=(left+right)/2;
//     if(f(mid)*f(right)<0) left=mid;
//     else right=mid;
// }printf("%lf",mid);
printf("%d\n\n\n", -2>>1);
//output:-1 because -2 is represented as 1111111111111111111111111111110 in binary, and the right shift operator shifts the bits to the right by 1, which results in 01111111111.
int	 j = 0xffffffff;//j=-1.,
auto 	k = (double)j;
//0xffffffff is the largest positive integer that can be represented by 32 bits.
//but j is a signed integer, so it has a sign bit.
//so why does j=-1.?
//because the rightmost bit of j is 1, which is the sign bit.
//0开头的数字表示负数，1开头的数字表示正数。
//十六进制的数字0x
//auto q=(double)j;  wrong,because j is a signed integer, and double can only represent positive numbers.
double q=(double)j;
printf("%lf\n",q);//q=-1.000000.
//forcefully convert j to double, and q=-1.000000.
//because the rightmost bit of j is 1, which is the sign bit.
//j begins with 0,me
	unsigned 	int	 i = j;

	printf("%u,%d\n",i,j);
//j=-1,i=4294967295.
//because the rightmost bit of i is 1, which is the sign bit.
return 0;
}