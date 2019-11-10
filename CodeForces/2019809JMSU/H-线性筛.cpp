#include <iostream>
#define MAXN 100005
using namespace std;
typedef long long LL;

bool isprime[MAXN] = {0};
int prime[MAXN], cnt;

void init() {
    cnt = 0;
    for (int i = 2; i < MAXN; ++i) {
        if (!isprime[i]) {
            prime[++cnt] = i;
            for (LL j = LL(i * i); j < MAXN; j += i) {
                isprime[j] = true;
            }
        }
    }
}

int main() {
    init();
    int t;
    cin >> t;
    while(t--) {
        int n, d;
        cin >> n >> d;
        int ans = 0;
        for (int i = 1; i <= cnt; ++i) {
            if (prime[i] * d >= n) break;
            ans++;
            if (d % prime[i] == 0) break;
        }
        cout << ans << endl;
    }
    return 0;
}