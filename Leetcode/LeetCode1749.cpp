// LeetCode 1749 任意子数组和的绝对值的最大值

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
    int maxAbsoluteSum(vector<int>& nums) {
        int pos_max = 0, neg_min = 0;
        int pos_sum = 0, neg_sum = 0;
        for (int num : nums) {
            pos_sum += num;
            pos_max = max(pos_max, pos_sum);
            pos_sum = max(0, pos_sum);
            neg_sum += num;
            neg_min = min(neg_min, neg_sum);
            neg_sum = min(0, neg_sum);
        }
        return max(pos_max, -neg_min);
    }
};