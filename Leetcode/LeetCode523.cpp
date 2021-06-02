// LeetCode 523 连续的子数组和
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 同余定理，如(n - m) % k == 0，则有n % k == m % k
class Solution {
   public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pre_sum = 0;
        unordered_map<int, int> mod_index;
        mod_index[0] = -1;
        for (int i = 0; i < n; ++i) {
            pre_sum += nums[i];
            int remainder = pre_sum % k;
            if (mod_index.find(remainder) != mod_index.end()) {
                if (i - mod_index[remainder] >= 2) {
                    return true;
                }
            } else {
                mod_index[remainder] = i;
            }
        }
        return false;
    }
};