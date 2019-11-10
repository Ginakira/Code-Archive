#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n, ans = 0;
    string s;
    cin >> n >> s;
    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < n - 1; ++i) {
        if(s[i] == 'V' && s[i + 1] == 'K') {
            ans++;
            s[i] = 'v', s[i + 1] = 'k';
        }
    }
    for(int i = 0; i < n - 1; ++i) {
        if(s[i] == s[i + 1]) {
            ans++;
            cout << ans << endl;
            return 0;
        }
    }

    cout << ans << endl;
    return 0;
}