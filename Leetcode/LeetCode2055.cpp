// LeetCode 2055 蜡烛之间的盘子

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        size_t n = s.size();
        vector<int> candles;
        vector<int> plates_pre_sum(n + 1, 0);
        for (size_t i = 0; i < n; ++i) {
            plates_pre_sum[i + 1] = plates_pre_sum[i];
            if (s[i] == '*') {
                ++plates_pre_sum[i + 1];
            } else {
                candles.push_back(i);
            }
        }

        vector<int> ans;
        for (auto& query : queries) {
            int left = query[0], right = query[1];
            auto left_it = lower_bound(candles.begin(), candles.end(), left);
            auto right_it = upper_bound(left_it, candles.end(), right);
            if (left_it == candles.end() || right_it == candles.begin()) {
                ans.push_back(0);
                continue;
            }
            int left_ind = *left_it, right_ind = *(right_it - 1);
            if (left_ind > right) {
                ans.push_back(0);
                continue;
            }
            ans.push_back(plates_pre_sum[right_ind + 1] -
                          plates_pre_sum[left_ind + 1]);
        }
        return ans;
    }
};