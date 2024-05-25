// LeetCode 2903 找出满足差值条件的下标 I

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
    vector<int> findIndices(vector<int>& nums, int indexDifference,
                            int valueDifference) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + indexDifference; j < n; ++j) {
                if (abs(nums[i] - nums[j]) >= valueDifference) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};

class Solution2 {
   public:
    vector<int> findIndices(vector<int>& nums, int indexDifference,
                            int valueDifference) {
        int n = nums.size();
        int min_idx = 0, max_idx = 0;
        for (int j = indexDifference; j < n; ++j) {
            int i = j - indexDifference;
            if (nums[i] < nums[min_idx]) {
                min_idx = i;
            }
            if (nums[j] - nums[min_idx] >= valueDifference) {
                return {min_idx, j};
            }
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
            if (nums[max_idx] - nums[j] >= valueDifference) {
                return {max_idx, j};
            }
        }
        return {-1, -1};
    }
};