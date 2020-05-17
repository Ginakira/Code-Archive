// 搜索插入位置
#include <vector>
using namespace std;

// 暴力 12ms
class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] >= target) break;
            ans++;
        }
        return ans;
    }
};

// 二分法 8ms
class Solution2 {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};

// 使用lower_bound()返回第一个大于等于target的迭代器 等效于二分搜索
class Solution3 {
   public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

// 000001111 找第一个大于等于target的位置
class Solution4 {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l != r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};