char* convertToBase7(int num) {
    if (num == 0) {
        char *ans = (char *)malloc(2 * sizeof(char));
        if (ans == NULL) {
            return NULL; // 内存分配失败
        }
        ans[0] = '0';
        ans[1] = '\0';
        return ans;
    }

    int isNegative = num < 0;
    if (isNegative) {
        num = -num;
    }

    // 计算需要的字符数
    int n = 1; // 至少需要一个字符
    int temp = num;
    while (temp >= 7) {
        temp /= 7;
        n++;
    }
    if (isNegative) {
        n++; // 负号占用一个字符
    }

    char *ans = (char *)malloc((n + 1) * sizeof(char));
    if (ans == NULL) {
        return NULL; // 内存分配失败
    }

    int index = n - 1;
    while (num > 0) {
        ans[index--] = (num % 7) + '0';
        num /= 7;
    }

    if (isNegative) {
        ans[0] = '-';
    }

    ans[n] = '\0';
    return ans;
}