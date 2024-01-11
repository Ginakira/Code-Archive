// LeetCode 260 只出现一次的数字III
#include <algorithm>
#include <climits>
#include <limits>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Solution1: 哈希表
class Solution {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            ++freq[num];
        }
        vector<int> ans;
        for (const auto& [num, occ] : freq) {
            if (occ == 1) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

// Solution2: 异或 再分组异或
class Solution2 {
   public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_result =
            std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
        int lowbit = xor_result == numeric_limits<int>::min()
                         ? xor_result
                         : xor_result & (-xor_result);
        int type1 = 0, type0 = 0;
        for (int num : nums) {
            if (num & lowbit) {
                type1 ^= num;
            } else {
                type0 ^= num;
            }
        }
        return {type1, type0};
    }
};
