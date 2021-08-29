// LeetCode 41 缺失的第一个正数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// 空间不是常数 最简单的方法
class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        for (int i = 1; i <= n; ++i) {
            if (!st.count(i)) {
                return i;
            }
        }
        return n + 1;
    }
};

// 使用数组作为哈希表 进行标记
class Solution2 {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};