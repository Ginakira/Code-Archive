// LeetCode 2789 合并后数组中的最大元素

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
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long sum = nums.back();
        for (int i = n - 2; i >= 0; --i) {
            sum = nums[i] <= sum ? sum + nums[i] : nums[i];
        }
        return sum;
    }
};
