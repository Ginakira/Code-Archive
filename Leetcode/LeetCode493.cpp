// LeetCode 493 翻转对
#include <vector>
using namespace std;

class Solution {
   public:
    int reversePairsRecursive(vector<int>& nums, int left, int right) {
        if (left == right) {
            return 0;
        }

        int ret = 0;
        int mid = (left + right) / 2;
        ret += reversePairsRecursive(nums, left, mid);
        ret += reversePairsRecursive(nums, mid + 1, right);

        // 统计重要翻转对个数
        int pa = left, pb = mid + 1;
        while (pa <= mid) {
            // 以左半部分为基准 找第一个右半部分不符合规则的
            // 则右半部分当前位置前面的数都能产生翻转对 加到答案中
            while (pb <= right && nums[pa] / 2.0 > nums[pb]) ++pb;
            ret += (pb - mid - 1);
            ++pa;
        }

        // 合并有序数组
        pa = left, pb = mid + 1;
        int ind = 0;
        vector<int> sorted(right - left + 1);
        while (pa <= mid || pb <= right) {
            if (pb > right || (pa <= mid && nums[pa] < nums[pb])) {
                sorted[ind++] = nums[pa++];
            } else {
                sorted[ind++] = nums[pb++];
            }
        }

        for (int i = 0; i < ind; ++i) {
            nums[left + i] = sorted[i];
        }

        return ret;
    }

    int reversePairs(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        return reversePairsRecursive(nums, 0, nums.size() - 1);
    }
};