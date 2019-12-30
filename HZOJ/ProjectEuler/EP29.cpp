/************************************************************
    File Name : EP29.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/29 14:15:48
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#define MAX_N 10000
#define MAX_M 210

int *result[MAX_N + 5];
int result_len = 0;

int find_result(int *num) {
    for (int i = 0; i < result_len; ++i) {
        if (memcmp(result[i], num, sizeof(int) * MAX_M) == 0) return i + 1;
    }
    return 0;
}

int *calc(int a, int b) {
    int *temp = (int *)calloc(sizeof(int), MAX_M);
    temp[0] = 1, temp[1] = 1;
    for (int i = 0; i < b; ++i) {
        for (int j = 1; j <= temp[0]; ++j) temp[j] *= a;
        for (int j = 1; j <= temp[0]; ++j) {
            if (temp[j] < 10) continue;
            temp[j + 1] += temp[j] / 10;
            temp[j] %= 10;
            temp[0] += (j == temp[0]);
        }
    }
    return temp;
}

int main() {
    for (int a = 2; a <= 100; ++a) {
        for (int b = 2; b <= 100; ++b) {
            int *temp = calc(a, b);
            if (find_result(temp) == 0) {
                result[result_len++] = temp;
            }
        }
    }
    cout << result_len << endl;
    return 0;
}