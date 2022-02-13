// LeetCode 1189 气球的最大数量

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> ch_cnt;
        for (char c : text) {
            ++ch_cnt[c];
        }
        int ans = INT_MAX;
        ans = min(ans, ch_cnt['b']);
        ans = min(ans, ch_cnt['a']);
        ans = min(ans, ch_cnt['l'] / 2);
        ans = min(ans, ch_cnt['o'] / 2);
        ans = min(ans, ch_cnt['n']);
        return ans;
    }
};