// LeetCode 775 全局倒置与局部倒置

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        size_t n = nums.size();
        int min_suff = nums[n - 1];
        for (int i = n - 3; i >= 0; --i) {
            if (nums[i] > min_suff) {
                return false;
            }
            min_suff = min(min_suff, nums[i + 1]);
        }
        return true;
    }
};