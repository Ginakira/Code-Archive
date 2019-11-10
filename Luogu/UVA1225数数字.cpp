#include <iostream>
#include <cstring>
using namespace std;

int cnt[10];

void stat(int n) {
    while(n > 0) {
        cnt[n % 10]++;
        n /= 10;
    }
    return ;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(cnt, 0, sizeof(cnt));
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i) stat(i);
        for(int i = 0; i < 10; ++i) {
            if(i == 0) cout << cnt[i];
            else cout << ' ' << cnt[i];
        }
        cout << endl;
    }
    return 0;
}