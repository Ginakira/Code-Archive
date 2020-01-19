/************************************************************
    File Name : #521-组合取数.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/13 16:02:51
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 1000000

int prime[MAXN + 5];
int is_prime[MAXN + 5];
int arr[35];

void init() {
    for (int i = 2; i < MAXN; ++i) {#include <stdio.h>
#include <inttypes.h>

typedef struct TEST_INFO {
    int testNum;
    int YesNum;
    int NoNum;
} TEST_INFO;

#define TEST(a, b) //TODO

#define EXPECT_EQ(a, b) { \
    (a) == (b) ? __ti->YesNum++ : __ti->NoNum++; \
    __ti->testNum++; \
}

int haizei_test_run(void (*func)(TEST_INFO *), const char *str1, const char *str2) {
    TEST_INFO ti = {0, 0, 0};
    printf("[RUN] %s.%s\n", str1, str2);
    func(&ti);
    if (ti.NoNum == 0) {
        printf("[OK] %s.%s %d pass %d failed\n", 
            str1, str2, ti.YesNum, ti.NoNum);
    } else {
        printf("[FAILED] %s.%s %d pass %d failed\n",
            str1, str2, ti.YesNum, ti.NoNum);
    }
    return 0;
}

int isPrime(int x);

TEST(isPrime, bound) {
    EXPECT_EQ(isPrime(0), 0);
    EXPECT_EQ(isPrime(1), 0);
    EXPECT_EQ(isPrime(INT32_MIN), 0);
}

TEST(isPrime, okTest) {
    #ifndef MAX_N
        #define MAX_N 100
    #endif
    int prime[MAX_N + 5] = {1, 1};
    for (int i = 2; i * i <= MAX_N; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        EXPECT_EQ(isPrime(i), prime[i] == 0);
    }
}

TEST(isPrime, failedTest) {
    #ifndef MAX_N
        #define MAX_N 100
    #endif
    int prime[MAX_N + 5] = {1, 1};
    for (int i = 2; i * i <= MAX_N; i++) {
        if (!prime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) {
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        EXPECT_EQ(isPrime(i), prime[i] == 1);
    }
}

int main() {
    return 0;
}

int isPrime(int x) {
    //TODO
}
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; ++j) {
            if (prime[j] * i > MAXN) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

int solve(int start, int remain, int sum) { return sum; }

int main() {
    init();
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!is_prime[solve(i, r, 0)]) ans++;
    }
    return 0;
}