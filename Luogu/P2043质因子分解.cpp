#include <iostream>
using namespace std;

int cnt[10010];

int main() {
    int n;
    cin >> n;
    for(int i = 2; i <= n; ++i) {
        int tmp = i;
        for(int j = 2; j <= i; ++j) {
            while(tmp % j == 0) {
                cnt[j]++;
                tmp /= j;
            }
        }
    }
    for(int i = 2; i <= n; ++i) {
        if(cnt[i] != 0) {
            cout << i << ' ' << cnt[i] << endl;
        }
    }
    return 0;
}