// LeetCode 1608 特殊数组的特征值

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); ++i) {
            auto it = lower_bound(nums.begin(), nums.end(), i);
            if (nums.end() - it == i) {
                return i;
            }
        }
        return -1;
    }
};