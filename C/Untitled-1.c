#include<stdio.h>
int is_leap_yeat(int x)
{
	a=1;
	if(x%4==0) a*=-1;
	if(x%100==0) a*=-1;
	if(x%400==0) a=-1;
	if(a==-1) return 1;//is
	else return 0;//not
}