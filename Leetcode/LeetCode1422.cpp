// LeetCode 1422 分割字符串的最大得分

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxScore(string s) {
        int ans = 0, n = s.size();
        vector<int> one_count(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            one_count[i + 1] = one_count[i];
            if (s[i] == '1') {
                ++one_count[i + 1];
            }
        }
        int zero_count = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '0') {
                ++zero_count;
            }
            ans = max(ans, zero_count + one_count[n] - one_count[i + 1]);
        }
        return ans;
    }
};

class Solution2 {
   public:
    int maxScore(string s) {
        int ans = 0, score = 0;
        for (char c : s) {
            if (c == '1') {
                ++score;
            }
        }
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') {
                ++score;
            } else {
                --score;
            }
            ans = max(ans, score);
        }
        return ans;
    }
};
