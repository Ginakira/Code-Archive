/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/12/12 19:02:19
************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_LEN 10005

int main() {
    int n;
    char str_a[MAX_LEN], str_b[MAX_LEN];
    scanf("%s", str_a);
    scanf("%d", &n);
    scanf("%s", str_b);

    // 第一问 第一种方法
    // printf("%lu\n", strlen(str_a));
    // 第一问 第二种方法
    int len_a = 0;
    while (str_a[len_a] != '\0') {
        ++len_a;
    }
    printf("%d\n", len_a);

    // 第二问
    for (int i = 0; i < len_a; ++i) {
        if (str_a[i] == 'a') {
            printf("%d\n", i + 1);
            break;
        }
    }

    // 第三问
    // 第一种做法
    /*
        char result[MAX_LEN];
        strcpy(result, str_a);
        strcpy(result + n - 1, str_b);
        strcpy(result + n + strlen(str_b) - 1, str_a + n - 1);
        printf("%s\n", result);
    */
    // 第二种做法
    char result[MAX_LEN];
    int ind = 0;
    for (int i = 0; i < n - 1; ++i) {
        result[ind] = str_a[i];
        ++ind;
    }
    for (int i = 0; str_b[i] != '\0'; ++i) {
        result[ind] = str_b[i];
        ++ind;
    }
    for (int i = n - 1; str_a[i] != '\0'; ++i) {
        result[ind] = str_a[i];
        ++ind;
    }
    printf("%s\n", result);
    return 0;
}