#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    string s, a;
    cin >> s;
    cin >> a;
    int s_len = s.size();
    unordered_map<char, int> mp;
    for (int i = 0; i < s_len; ++i) {
        mp[s[i]] = i;
    }

    int pre = -1, waste = 0;
    for (char c : a) {
        if (!mp.count(c)) {
            cout << -1 << endl;
            return 0;
        }
        int pos = mp[c];
        if (pos >= pre) {
            waste += pos - pre - 1;
        } else {
            waste += s_len - pre + pos - 1;
        }
        pre = mp[c];
    }
    cout << waste << endl;
    return 0;
}