#include <iostream>
#define MAXN 1000010
using namespace std;

bool is_prime[MAXN];
int prime[MAXN], prime_cnt = 0;

void prime_init() {
    fill(is_prime, is_prime + MAXN, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXN; ++i) {
        if (is_prime[i]) prime[prime_cnt++] = i;
        for (int j = 0; j < prime_cnt && i * prime[j] < MAXN; ++j) {
            is_prime[i * prime[j]] = false;
            if (!(i % prime[j])) break;
        }
    }
    return;
}