// LeetCode 869 重新排序得到2的幂

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    vector<int> vis;

    bool is_pow_of_two(int n) { return !(n & (n - 1)); }

    bool backtrace(const string &nums, int ind, int num) {
        if (ind == nums.size()) {
            return is_pow_of_two(num);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if ((num == 0 && nums[i] == '0') || vis[i] ||
                (i > 0 && !vis[i - 1] && nums[i] == nums[i - 1])) {
                continue;
            }
            vis[i] = true;
            if (backtrace(nums, ind + 1, num * 10 + nums[i] - '0')) {
                return true;
            }
            vis[i] = false;
        }
        return false;
    }

   public:
    bool reorderedPowerOf2(int n) {
        string str = to_string(n);
        vis.resize(str.size(), false);
        return backtrace(str, 0, 0);
    }
};