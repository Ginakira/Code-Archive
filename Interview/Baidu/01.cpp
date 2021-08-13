#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int find_ans(vector<int> &values, int target) {
    int left = 0, right = values.size(), mid;
    while (left < right) {
        mid = (left + right) >> 1;
        if (values[mid] >= target) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return values.size() - left;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> require(n), value(m);
    for (int i = 0; i < n; ++i) cin >> require[i];
    for (int i = 0; i < m; ++i) cin >> value[i];
    sort(value.begin(), value.end());
    for (int i = 0; i < n; ++i) {
        i != 0 && cout << ' ';
        cout << find_ans(value, require[i]);
    }
    cout << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}