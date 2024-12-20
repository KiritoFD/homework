#include<stdio.h>
#include<string.h>
#include<ctype.h>
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
    for(int i=0;i<strlen(a);i++){
        a[i]=tolower(a[i]);//        if(a[i]>='A'&&a[i]<='Z') a[i]+='a'-'A';
    }
    ToLowerCase(a);
    printf("%s",a);
}