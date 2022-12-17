// LeetCode 1764 通过连接另一个数组的子数组得到一个数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    bool check(const vector<int> &group, const vector<int> &nums,
               int nums_ind) {
        for (int i = 0; i < group.size(); ++i) {
            if (group[i] != nums[i + nums_ind]) {
                return false;
            }
        }
        return true;
    }

   public:
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums) {
        int nums_ind = 0, nums_n = nums.size();
        int groups_ind = 0, groups_n = groups.size();
        while (nums_ind < nums_n && groups_ind < groups_n) {
            auto &group = groups[groups_ind];
            if (nums_n - nums_ind < group.size()) {
                return false;
            }
            if (check(group, nums, nums_ind)) {
                nums_ind += group.size();
                ++groups_ind;
            } else {
                ++nums_ind;
            }
        }
        return groups_ind == groups_n;
    }
};