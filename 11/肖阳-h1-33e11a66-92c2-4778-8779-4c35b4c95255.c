
#include<string.h>
int strStr(char* haystack, char* needle) {
    int h=strlen(haystack),n=strlen(needle);
    int judge=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            if(haystack[i+j]!=needle[j]) judge=0;
        }
        if(judge) return i+1;
        judge=1;
    }
    return -1;
}