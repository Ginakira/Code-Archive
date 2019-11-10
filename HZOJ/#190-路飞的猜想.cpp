#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#define MAXN 8000010
using namespace std;

bool is_prime[MAXN];

void init() {
    is_prime[0] = is_prime[1] = false;
    is_prime[2] = true;
    memset(is_prime, true, sizeof(is_prime));
    for(int i = 2; i * i <= MAXN; ++i) {
        if(is_prime[i] == true) {
            for(int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    int n, cnt = 0;
    cin >> n;
    init();
    for(int i = 2; i <= n / 2; ++i) {
        int j = n - i;
        if(!is_prime[i] || !is_prime[j]) continue;
        else if(i + j == n) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}