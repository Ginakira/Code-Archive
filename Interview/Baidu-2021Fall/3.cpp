#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solve(string s, int n) {
    string sa = s, sb;
    sort(sa.begin(), sa.end());
    sb = sa;
    reverse(sb.begin(), sb.end());
    
    int diff_a = 0, diff_b = 0;
    for (int i = 0; i < n; ++i) {
        diff_a += (s[i] != sa[i]);
        diff_b += (s[i] != sb[i]);
    }
    return min(diff_a, diff_b);
}

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    for (int i = 0; i < q; ++i) {
        cin >> s;
        cout << solve(s, n) << endl;
    }
    return 0;
}