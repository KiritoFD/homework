#include <stdio.h>
int main() {
    int a = 10;
    float b = 3.14;
    char c = 'A';
    unsigned int d = -100;
    printf("a = %d\n", a);
    printf("b = %f\n", b);
    printf("%e\n", b);//3.140000e+00
    printf("c = %c\n", c);    
    printf("d = %u\n", d);//d=4294967196
    //if unsigend is negative,it will be(2*int_max+1)-unsigned_num
    //so d=4294967196=2^32-100
    //format:
    // ' - ':left justified
    // '0':pad with zero
    // '+' or ' ':show sign
    //'w':minimum width:if less than w,add space;
    //if more than w,output as is
    //'.p':precision:number of digits after decimal point
    //for string:only the first p characters are printed
    // 'e' or 'E':scientific notation
    // 'g' or 'G':general format
    printf("%c,%-3c,%2c\n", 045, 'a', 'a');// 八进制045对应的字符是%
    //   %,a  , a
    printf("%f,%8.3f,%-7.2f,%.7f\n", 123.4567f,123.4567f,123.4567f, 123.456789);
    //%8.3f:8-wide field,3-digit precision,right justified
    //%-7.2f:7-wide field,2-digit precision,left justified
    //%.7f:7-wide field,no precision,right justified
    //input:
    char str[100];
    scanf("%4c", str);//read 4 characters
    scanf("%s", str);//read until space or end of line
    scanf("%4s", str);//read 4 characters,without space,have'\0' at the end
    //string is terminated by '\0'
    //strings:
    //void strcat(char *dest, const char *src);
    //void strcpy(char *dest, const char *src);
    //int strcmp(const char *s1, const char *s2);
    //int strncmp(const char *s1, const char *s2, size_t n);
    //size_t strlen(const char *s);
    //char *strchr(const char *s, int c);
    //char *strrchr(const char *s, int c);
    //char *strstr(const char *haystack, const char *needle);
    //char *strtok(char *str, const char *delim);
    //void *memcpy(void *dest, const void *src, size_t n);
    //void *memmove(void *dest, const void *src, size_t n);
    //void *memset(void *s, int c, size_t n);
    //int memcmp(const void *s1, const void *s2, size_t n);
    //void *calloc(size_t nmemb, size_t size);
    //int is_prefix(const char *s1, const char *s2);
    int i, j;
    scanf("%3d%*4d%d", &i, &j);//read 3 digits,ignore 4 digits,read 1 digit
    //%*4d:ignore 4 digits
    //%d:read 1 integer
    return 0;
}