#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* multiply(char* num1, char* num2) {
    if (num1 == NULL || num2 == NULL || num1[0] == '0' || num2[0] == '0') {
        // Handle case where either number is "0"
        char *ret = (char*)malloc(2);
        ret[0] = '0';
        ret[1] = '\0';
        return ret;
    }

    int i1, j1, len1 = strlen(num1), len2 = strlen(num2), len = len1 + len2;
    long int *ans = (long int*)malloc(sizeof(long int) * len); // Store the result
    for (int i = 0; i < len; i++) ans[i] = 0;

    // Multiply each digit of num1 by each digit of num2 and store in ans
    for (int i = len1 - 1; i >= 0; i--) {   // Start from the least significant digit of num1
        i1 = num1[i] - '0';
        for (int j = len2 - 1; j >= 0; j--) { // Start from the least significant digit of num2
            j1 = num2[j] - '0';
            ans[i + j + 1] += i1 * j1;  // Store product at correct position
        }
    }

    // Handle carry-over/overflow from multiplication
    for (int i = len - 1; i > 0; i--) {
        ans[i - 1] += ans[i] / 10;  // Carry over
        ans[i] %= 10;               // Keep only the digit
    }

    // Remove leading zeros
    int start = 0;
    while (start < len && ans[start] == 0) {
        start++;
    }

    // If the number is 0, return "0"
    if (start == len) {
        char *ret = (char*)malloc(2);
        ret[0] = '0';
        ret[1] = '\0';
        free(ans);
        return ret;
    }

    // Allocate memory for the result string
    char *ret = (char*)malloc(len - start + 1);  // +1 for '\0'

    // Convert digits to characters
    int idx = 0;
    for (int i = start; i < len; i++) {
        ret[idx++] = ans[i] + '0';  // Convert each integer to a character
    }

    ret[idx] = '\0';  // Null-terminate the result string

    // Free allocated memory
    free(ans);
    return ret;
}