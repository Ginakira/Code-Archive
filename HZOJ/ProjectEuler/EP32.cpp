/************************************************************
    File Name : EP32.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/22 16:27:38
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 10000

int keep[MAXN + 5] = {0};

int add_to_num(int *num, int n) {
    while (n) {
        if (num[n % 10]) return 0;
        num[n % 10]++;
        n /= 10;
    }
    return 1;
}

int digits(int n) {
    if (!n) return 1;
    return floor(log10(n)) + 1;
}

int is_val(int a, int b) {
    if (digits(a) + digits(b) + digits(a * b) - 9) return 0;
    int num[10] = {0};
    int flag = 1;
    num[0] = 1;
    flag = flag && add_to_num(num, a);
    flag = flag && add_to_num(num, b);
    flag = flag && add_to_num(num, a * b);
    return flag;
}

int main() {
    int sum = 0;
    for (int a = 1; a < 100; ++a) {
        for (int b = a + 1; b < 10000; ++b) {
            if (!is_val(a, b)) continue;
            if (keep[a * b]) continue;
            keep[a * b] = 1;
            sum += a * b;
            printf("%d * %d = %d\n", a, b, a * b);
        }
    }
    printf("%d\n", sum);
    return 0;
}