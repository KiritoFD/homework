#include <string.h>

char findTheDifference(char* s, char* t) {
    char result = 0;  // 初始化结果为0
    int lens = strlen(s);
    int lent = strlen(t);

    // 对 `s` 和 `t` 中的所有字符执行异或操作
    for (int i = 0; i < lens; i++) {
        result ^= s[i];
    }
    for (int i = 0; i < lent; i++) {
        result ^= t[i];
    }

    // 返回结果
    return result;
}
