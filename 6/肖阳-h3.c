char* decodeMessage(char* key, char* message) {  
    char k[26] = {0}; // 初始化为0，表示没有映射  
    int len = strlen(message),i1=-1;  
    for (int i = 0; i < strlen(key); i++) {  
        if (key[i] >= 'a' && key[i] <= 'z' && k[key[i] - 'a'] == 0) {  
            i1++;
            k[key[i] - 'a'] = 'a' + (i1 % 26); // 使用模运算避免超出'a'-'z'范围  
        }  
    }  
    char *ans = (char*)malloc(sizeof(char) * (len + 1)); // 分配len+1个字符的空间  
    if (ans == NULL) {  
        return NULL; // 内存分配失败  
    }  
    for (int i = 0; i < len; i++) {  
        if (message[i] >= 'a' && message[i] <= 'z') {  
            ans[i] = k[message[i] - 'a'];  
        } else {  
            ans[i] = message[i];  
        }  
    }  
    ans[len] = '\0'; // 添加字符串末尾的空字符  
    return ans;  
}