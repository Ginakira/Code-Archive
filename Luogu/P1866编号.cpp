#include <iostream>
#include <algorithm>
using namespace std;

int a[100];
int cnt[10000];
int main() {
    int n;
    bool fail = false;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
        if(cnt[a[i]] > a[i]) fail = true;
    }
    if(fail) {
        cout << 0 << endl;
        return 0;
    }
    sort(a, a + n);
    long long ans = 1;
    for(int i = 0; i < n; ++i) {
        ans = ans * (a[i] - i) % 1000000007;
        //cout << ans << endl;
    }
    cout << ans << endl;
    return 0;
}