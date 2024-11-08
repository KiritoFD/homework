#include<stdio.h>
#include<string.h>
void ToLowerCase(char* str) {
    int i=strlen(str);
    while(i>0){
        i--;char s=str[i];
        if(s>='A'&&s<='Z') str[i]+='a'-'A';
    }
}
int main()
{
    char a[100];
    scanf("%s",a);
    ToLowerCase(a);
    printf("%s",a);
}