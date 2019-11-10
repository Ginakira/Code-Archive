#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    long long n, cnt = 0, man = 0, ans = 0, tmp;
    cin >> n;
    char c;
    string id;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if(c == 'i') {
            cnt++;
            cin >> id;
            if ((id[id.length() - 2] - '0') % 2 != 0) man++;
        } else if(c == 'q') {
            cin >> tmp;
            ans += tmp;
        }
    }
    if (n - cnt) ans = ans / (n - cnt);
    else
        ans = 0;
    cout << man << ' ' << cnt - man << ' ' << ans;
    return 0;
}