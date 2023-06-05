// LeetCode 2460 对数组执行操作

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
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        stable_sort(nums.begin(), nums.end(),
                    [](int a, int b) { return b == 0; });
        return nums;
    }
};

class Solution2 {
   public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0, j = 0; i < n; ++i) {
            if (i + 1 < n && nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                ++j;
            }
        }
        return nums;
    }
};