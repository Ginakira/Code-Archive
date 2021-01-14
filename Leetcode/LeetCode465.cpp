// LeetCode 485 最大连续1的个数
#include <algorithm>
#include <vector>
using namespace std;

// 统计0的个数 计算差值 但需要特判的情况较多 56ms 33.4MB
class Solution {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> zero{-1};
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) zero.emplace_back(i);
        }
        zero.push_back(nums.size());
        int ans = 0;
        for (int i = 1; i < zero.size(); ++i) {
            ans = max(ans, zero[i] - zero[i - 1] - 1);
        }

        return ans;
    }
};

// 维护计数变量，遇到0取最大值归零，遇到1计数++ 36ms 32.6MB
class Solution2 {
   public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, maxCount = 0;
        for (const int& num : nums) {
            if (num == 0) {
                maxCount = max(count, maxCount);
                count = 0;
            } else {
                count++;
            }
        }
        return max(count, maxCount);
    }
};