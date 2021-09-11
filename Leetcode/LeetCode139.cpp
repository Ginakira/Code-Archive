// LeetCode 139 单词拆分

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// dp[i] 代表前i个字符是否能被合法拆分
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for (auto& word : wordDict) {
            st.insert(word);
        }
        int n = s.size();
        vector<int> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && st.find(s.substr(j, i - j)) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};