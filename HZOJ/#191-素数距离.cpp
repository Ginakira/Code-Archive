/************************************************************
    File Name : #191-素数距离.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/21 20:14:20
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#define MAXN 8000000

int is_prime[MAXN + 5];
int prime[MAXN + 5];

void init(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; ++j) {
            if (prime[j] * i > n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

int main() {
    int l, r;
    cin >> l >> r;
    init(r);
    int index = 1;
    while (prime[index] < l) index++;
    if (index == prime[0]) {
        cout << "There are no adjacent primes.\n";
        return 0;
    }
    int a, b, c, d, mind = MAXN, maxd = 0;
    for (int i = index; i < prime[0]; ++i) {
        int dist = prime[i + 1] - prime[i];
        if (dist > maxd) {
            c = prime[i], d = prime[i + 1];
            maxd = dist;
        }
        if (dist < mind) {
            a = prime[i], b = prime[i + 1];
            mind = dist;
        }
    }
    printf("%d,%d are closest, %d,%d are most distant.\n", a, b, c, d);
    return 0;
}