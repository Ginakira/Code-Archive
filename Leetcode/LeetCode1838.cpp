// LeetCode 1838 最高频元素的频数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 暴力法 超时
class Solution {
   public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        int max_freq = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            int ind = i - 1, remain = k;
            while (ind >= 0 && remain >= nums[i] - nums[ind]) {
                remain -= nums[i] - nums[ind];
                --ind;
            }
            max_freq = max(max_freq, i - ind);
        }
        return max_freq;
    }
};

// 排序 + 滑动窗口
class Solution2 {
   public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long total = 0;  // 窗口内数值变换成nums[r]需要的操作次数
        int ans = 1;          // 最高频次
        int l = 0, r = 1, n = nums.size();

        for (int r = 1; r < n; ++r) {
            total += (long long)(nums[r] - nums[r - 1]) * (r - l);
            while (total > k) {
                total -= (nums[r] - nums[l]);
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

// 前缀和 + 二分窗口长度
class Solution3 {
   private:
    bool check(vector<int>& nums, vector<long long>& sum, int k, int len) {
        int n = sum.size() - 1;
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            long long target = (long long)nums[r] * len,
                      current = sum[r + 1] - sum[l];
            if (target - current <= k) {
                return true;
            }
        }
        return false;
    }

   public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0, right = n, mid;
        vector<long long> sum(n + 1);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        while (left < right) {
            mid = left + (right - left + 1) / 2;
            if (check(nums, sum, k, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};