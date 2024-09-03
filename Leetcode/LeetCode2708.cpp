// LeetCode 2708 一个小组的最大实力值

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    long long maxStrength(vector<int>& nums) {
        int neg_cnt = 0, zero_cnt = 0, pos_cnt = 0;
        long long prod = 1;
        int max_neg = numeric_limits<int>::min();
        for (int num : nums) {
            if (num < 0) {
                ++neg_cnt;
                prod *= num;
                max_neg = max(max_neg, num);
            } else if (num > 0) {
                ++pos_cnt;
                prod *= num;
            } else {
                ++zero_cnt;
            }
        }
        if (neg_cnt == 1 && zero_cnt == 0 && pos_cnt == 0) {
            return max_neg;
        }
        if (neg_cnt <= 1 && pos_cnt == 0) {
            return 0;
        }
        return prod < 0 ? prod / max_neg : prod;
    }
};