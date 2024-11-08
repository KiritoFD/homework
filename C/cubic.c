#include <stdio.h>  
#include <assert.h>  
#include <math.h>  
#include <stdbool.h>  
  
// 定义一个非常小的值作为收敛标准  
#include<stdio.h>
#include<math.h>
int count=0,i,j;
double sol[3]={-10,-20,-30},a,b,c,d,er=0.00000001,s1,a1,b1,c1;//ax^3+bx^2+cx+d=0,error=er
double f(double x){
    return a*x*x*x+b*x*x+c*x+d;
}
  
// 求解三次方程的所有实根  
void solve_cubic_equ(double c2, double c1, double c0, double eps, int* cnt, double* sol) {  
     a=1;b=c2;c=c1;d=c0;
     double low=0,top=1,s1;
    while (f(low)*f(top)>0){
        low--;top++;
    }
    while(top-low>er||f(s1)>er){
        s1=(top+low)/2;
        if(f(s1)==0) break;
        if(f(s1)*f(low)>0) low=s1;
        else top=s1;
    }sol[0]=s1;*cnt=1;
    a1=a,b1=b+a*s1,c1=c+b*s1+a*s1*s1;
   double delta=b1*b1-4*a1*c1;//printf("%lf",delta);
    if(delta<0) ;
    else{
    if(delta<0.001) {
        count=1;
        sol[1]=-b1/a1/2;
    }
    else{delta=sqrt(delta);
    count=2;
    sol[1]=(delta-b1)/a1/2;
    sol[2]=(-delta-b1)/a1/2;
    }
    }//if(fabs(sol[1]-sol[2])<0.00001) count--;
    double mid;
    for(i=0;i<=count;i++){
        for(j=i+1;j<=count;j++){
            if(sol[i]>sol[j]){
                mid=sol[i];
                sol[i]=sol[j];
                sol[j]=mid;
            }
        }
    }*cnt=count+1;
    if(count==2) printf("%.lf",sol[1]-sol[2]);
    if(count==2&&fabs(sol[1]-sol[2])<0.001) *cnt=2;
}  
  
// 测试用例  
void TestCase1() {  
    double eps = 1e-6;  
    int cnt;  
    double sol[3];  
    solve_cubic_equ(0, 0, -1, eps, &cnt, sol);  
    printf("Test Case 1: Expected 1 root, x = 1\n");  
    printf("Number of roots: %d\n", cnt);  
    for (int i = 0; i < cnt; i++) {  
        printf("Root %d: %.6f\n", i + 1, sol[i]);  
    }  
    assert(cnt == 1 && fabs(sol[0] - 1) < eps);  
    printf("Passed TestCase1\n");  
}  
  
void TestCase2() {  
    double eps = 1e-6;  
    int cnt;  
    double sol[3];  
    solve_cubic_equ(0, -3, 2, eps, &cnt, sol);  
    printf("Test Case 2: Expected 2 roots, x = 1 (double), x = -2\n");  
    printf("Number of roots: %d\n", cnt);  
    for (int i = 0; i < cnt; i++) {  
        printf("Root %d: %.6f\n", i + 1, sol[i]);  
    }  
    // 注意：由于浮点数精度问题，可能无法准确判断双重根，这里只检查根的数量和接近程度  
    bool passed = (cnt == 2 && (fabs(sol[0] + 2) < eps || fabs(sol[1] + 2) < eps) && (fabs(sol[0] - 1) < eps || fabs(sol[1] - 1) < eps));  
    if (cnt == 2) {  
        // 确保有一个根非常接近1，另一个根非常接近-2  
        if (fabs(sol[0] - 1) < eps) {  
            assert(fabs(sol[1] + 2) < eps);  
        } else {  
            assert(fabs(sol[0] + 2) < eps);  
            assert(fabs(sol[1] - 1) < eps);  
        }  
    }  
    printf("Passed TestCase2: %s\n", passed ? "Yes" : "No");  
}  
  
void TestCase3() {  
    double eps = 1e-6;  
    int cnt;  
    double sol[3];  
    solve_cubic_equ(-6, 11, -6, eps, &cnt, sol);  
    printf("Test Case 3: Expected 3 roots, x = 1, 2, 3\n");  
    printf("Number of roots: %d\n", cnt);  
    for (int i = 0; i < cnt; i++) {  
        printf("Root %d: %.6f\n", i + 1, sol[i]);  
    }  
    assert(cnt == 3 && fabs(sol[0] - 1) < eps && fabs(sol[1] - 2) < eps && fabs(sol[2] - 3) < eps);  
    printf("Passed TestCase3\n");  
}  
  
int main() {  
    TestCase1();  
    TestCase2();  
    TestCase3();  
    return 0;  
}