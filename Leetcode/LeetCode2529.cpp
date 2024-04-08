// LeetCode 2529 正整数和负整数的最大计数

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
    int maximumCount(vector<int>& nums) {
        return max(ranges::count_if(nums, [](int num) { return num > 0; }),
                   ranges::count_if(nums, [](int num) { return num < 0; }));
    }
};