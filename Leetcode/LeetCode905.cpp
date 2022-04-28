// LeetCode 905 按奇偶排序数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(),
             [](int a, int b) { return (b & 1) && !(a & 1); });
        return nums;
    }
};