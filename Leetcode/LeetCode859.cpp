// LeetCode 859 亲密字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool buddyStrings(string s, string goal) {
        int n = s.size(), m = goal.size();
        if (n != m) return false;

        vector<int> s_cnt(26, 0), goal_cnt(26, 0);
        int diff_cnt = 0;
        for (int i = 0; i < n; ++i) {
            char ch_s = s[i], ch_goal = goal[i];
            ++s_cnt[ch_s - 'a'];
            ++goal_cnt[ch_goal - 'a'];
            if (ch_s != ch_goal) {
                ++diff_cnt;
            }
        }

        bool valid = false;
        for (int i = 0; i < 26; ++i) {
            if (s_cnt[i] != goal_cnt[i]) return false;
            if (s_cnt[i] >= 2) valid = true;
        }
        return diff_cnt == 2 || (diff_cnt == 0 && valid);
    }
};