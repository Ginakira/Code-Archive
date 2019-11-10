#include <iostream>
#include <cmath>
using namespace std;

bool notPrime[10000000] = {0};

inline void Linear(int n) {
    for(int i = 2; i * i <= n; ++i) {
        if(!notPrime[i]) {
            for(int j = 2; i * j <= n; ++j) notPrime[i * j] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    notPrime[1] = 1;
    int n, m;
    cin >> n >> m;
    Linear(m + 1);
    int l, r, ans = 0;
    while(n--) {
        ans = 0;
        cin >> l >> r;
        if(l < 1 || r < 1 || r > m || l > m) cout << "Crossing the line\n";
        else {
            for(int i = l; i <= r; ++i) {
                if(!notPrime[i]) {
                    //cout << "#" << i << endl;
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}