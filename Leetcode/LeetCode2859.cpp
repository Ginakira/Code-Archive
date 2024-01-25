// LeetCode 2859 计算K置位下标对应元素的和

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
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int cnt = __builtin_popcount(i);
            if (cnt != k) {
                continue;
            }
            sum += nums[i];
        }
        return sum;
    }
};