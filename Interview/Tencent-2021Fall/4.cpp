#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ans;
int n, k;
string s;

int counts = 0;

void backtrace(int cur, string &temp) {
    if (!ans.empty() && ans.substr(0, temp.size()) > temp) return;
    if (temp.size() == k) {
        ++counts;
        cout << temp << endl;
        ans = max(ans, temp);
        return;
    }

    for (int i = cur; i < n; ++i) {
        temp.push_back(s[i]);
        backtrace(i + 1, temp);
        temp.pop_back();
    }
}

int main() {
    cin >> n >> k;
    cin >> s;
    string temp;

    for (int i = 0; i <= n - k; ++i) {
        if (!ans.empty() && ans[0] > s[i]) continue;
        temp.push_back(s[i]);
        backtrace(i + 1, temp);
        temp.pop_back();
    }

    cout << counts << endl;
    cout << ans << endl;
    return 0;
}