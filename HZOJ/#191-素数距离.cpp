#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#define MAXN 8000010
using namespace std;

bool is_prime[MAXN];
int prime[MAXN];

void init() {
    is_prime[0] = is_prime[1] = false;
    is_prime[2] = true;
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i * i <= MAXN; ++i) {
        if (is_prime[i] == true) {
            for (int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2, j = 0; i < MAXN; ++i) {
        if (is_prime[i]) {
            prime[j++] = i;
        }
    }
}

int main() {
    init();
    int l, r;
    cin >> l >> r;
    bool exsist = false;
    int a = 0, b = 0, c = 0, d = 0;
    int lb = 0, rb = 0;
    for(int i = 0; prime[i] < l; ++i) lb++;
    rb = lb;
    for(int i = lb; prime[i] < r; ++i) rb++;
    int maxd = -9999, mind = 0x3f3f3f3f;
    for (int i = lb; i < rb; ++i) {
        if (prime[i + 1] - prime[i] < mind && i + 1 < rb) {
            mind = prime[i + 1] - prime[i];
            a = prime[i], b = prime[i + 1];
            exsist = true;
        }
    }
    for (int i = lb; i < rb && exsist; ++i) {
        if (prime[i + 1] - prime[i] > maxd && i + 1 < rb) {
            maxd = prime[i + 1] - prime[i];
            c = prime[i], d = prime[i + 1];
        }
    }
    if (exsist) {
        cout << a << "," << b << " are closest, " << c << "," << d
             << " are most distant.";
    } else {
        cout << "There are no adjacent primes.";
    }

    return 0;
}
