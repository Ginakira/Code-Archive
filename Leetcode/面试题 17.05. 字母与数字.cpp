// 面试题 17.05. 字母与数字

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        vector<int> presum(n + 1, 0);
        unordered_map<int, int> first_sum_ind;
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + (isalpha(array[i - 1][0]) ? 1 : -1);
        }
        first_sum_ind[0] = 0;

        int ans_begin = 0, ans_end = 0;
        for (int i = 1; i <= n; ++i) {
            auto it = first_sum_ind.find(presum[i]);
            if (it == first_sum_ind.end()) {
                first_sum_ind[presum[i]] = i;
            } else if (i - it->second > ans_end - ans_begin) {
                ans_begin = it->second;
                ans_end = i;
            }
        }
        auto begin_it = array.begin();
        return {next(begin_it, ans_begin), next(begin_it, ans_end)};
    }
};