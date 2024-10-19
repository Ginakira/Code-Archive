// LeetCode 908 最小差值 I
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_num = *min_element(nums.begin(), nums.end());
        int max_num = *max_element(nums.begin(), nums.end());
        return max_num - min_num <= 2 * k ? 0 : max_num - min_num - 2 * k;
    }
};

class Solution2 {
   public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min_elem = *ranges::min_element(nums);
        int max_elem = *ranges::max_element(nums);
        return max(0, max_elem - min_elem - k * 2);
    }
};