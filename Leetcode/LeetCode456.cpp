// LeetCode 456 132模式

#include <algorithm>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 枚举3
class Solution {
   public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int min_num = nums[0];

        if (n < 3) return false;

        multiset<int> ms(nums.begin() + 2, nums.end());

        for (int i = 1; i < n - 1; ++i) {
            if (min_num < nums[i]) {
                auto it = ms.upper_bound(min_num);
                if (it != ms.end() && *it < nums[i]) {
                    return true;
                }
            }
            min_num = min(min_num, nums[i]);
            ms.erase(ms.find(nums[i + 1]));
        }
        return false;
    }
};