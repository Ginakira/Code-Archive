// LeetCode 2873 有序三元组中的最大值 I

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
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long max_val = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    max_val = max(max_val, 1LL * (nums[i] - nums[j]) * nums[k]);
                }
            }
        }
        return max_val;
    }
};