#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> value(26);
    for (int i = 0; i < 26; ++i) {
        cin >> value[i];
    }
    string s, t;
    cin >> s >> t;
    int s_len = s.size(), t_len = t.size();
    vector<vector<int>> dp(s_len, vector<int>(t_len));
    for (int i = 0; i < s_len; ++i) {
        for (int j = 0; j < t_len; ++j) {
            if (s[i] == t[j]) {
                dp[i][j] = 2 * value[s[i] - 'a'];
            } else if (i >= 1 && j >= 1) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[s_len - 1][t_len - 1] << endl;
    return 0;
}