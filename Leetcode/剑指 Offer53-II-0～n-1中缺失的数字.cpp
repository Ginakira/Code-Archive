// 剑指 Offer 53 - II. 0～n-1中缺失的数字
#include <vector>
using namespace std;

// 线性遍历 12ms
class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i != nums[i]) return i;
        }
        return n;
    }
};

// 二分法 16ms
class Solution2 {
   public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};