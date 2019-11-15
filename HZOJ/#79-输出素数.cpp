/************************************************************
    File Name : #79-输出素数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-15 10:48:00
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#define MAXN 10000100
using namespace std;

bool is_prime[MAXN];

void init(int num) {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAXN; ++i) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    init(b);
    for(int i = a; i <= b; ++i) {
        if(is_prime[i]) printf("%d\n", i);
    }
    return 0;
}