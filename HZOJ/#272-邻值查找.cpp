#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, temp;
    cin >> n;
    set<pair<int, int>> s;
    cin >> temp;
    s.insert({temp, 1});
    for (int i = 2; i <= n; ++i) {
        cin >> temp;
        auto iter = s.insert({temp, i});
        auto it = iter.first;
        pair<int, int> ans = {0x3f3f3f3f, -1};
        if (++it != s.end()) {
            ans = {(*it).first - temp, (*it).second};
        }
        --it;
        if (it-- != s.begin() && ans.first >= temp - (*it).first) {
            ans = {temp - (*it).first, (*it).second};
        }
        cout << ans.first << ' ' << ans.second << endl;
    }
    return 0;
}