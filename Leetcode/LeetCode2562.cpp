// LeetCode 2562 找出数组的串联值

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    long long findTheArrayConcVal(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        long long concat_val = 0;
        for (int l = 0, r = n - 1; l < r; ++l, --r) {
            std::string concat_str =
                std::to_string(nums[l]) + std::to_string(nums[r]);
            concat_val += std::stoi(concat_str);
        }
        if (n & 1) {
            concat_val += nums[n / 2];
        }
        return concat_val;
    }
};
