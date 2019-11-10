#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, cnt = 0, ans = 0, tmp;
    cin >> n;
    string s;
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if(c == 'C') {
            cin >> s;
            cnt++;
        }
        else if(c == 'N') {
            cin >> tmp;
            ans += tmp;
        }
    }
    cout << cnt << ' ' << ans / (n - cnt);
    return 0;
}