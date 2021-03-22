// 剑指 Offer 53 - I.在排序数组中查找数字 I
#include <vector>
using namespace std;

// S1 遍历
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int count = 0;
        for (const int& num : nums) {
            if (num == target) {
                ++count;
            }
        }
        return count;
    }
};

