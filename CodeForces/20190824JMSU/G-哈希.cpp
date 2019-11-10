#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int num[3100], cnt[10010];

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                cnt[num[i] + num[j]]++;
            }
        }
        for (int i = 10000; m > 0; ) {
            if(cnt[i] && m) {
                if(m == 1) {
                    cout << i << endl;
                }
                else
                    cout << i << ' ';
                m--;
                cnt[i]--;
            }
            else
                --i;
        }
    }
    return 0;
}
